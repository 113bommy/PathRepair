#include <algorithm>
#include <set>
#include <bitset>
#include <cstdio>
#include <map>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

struct Piece
{
	int h, w, area, topleft;
	int map[20];
	
	void input(bool inv)
	{
		scanf("%d%d", &h, &w);
		rep(i, h){
			char str[32];
			scanf("%s", str);
			map[i] = 0;
			rep(j, w){
				if((str[j]=='#') ^ inv)
					map[i] |= (1 << j);
			}
		}
	}
	
	void trim()
	{
		int top=h,bottom=0,left=w,right=0;
		rep(i, h) rep(j, w){
			if((map[i]>>j)&1){
				top = min(top, i);
				bottom = max(bottom, i);
				left = min(left, j);
				right = max(right, j);
			}
		}
		++bottom;
		++right;
		
		int tmp[20];
		copy(map, map+h, tmp);
		fill(map, map+h, 0);
		reps(i, top, bottom) reps(j, left, right){
			map[i-top] |= ((tmp[i]>>j)&1) << (j-left);
		}
		
		h = bottom - top;
		w = right - left;
	}
	
	void dump()
	{
		rep(i, h){
			rep(j, w)
				putchar((map[i]>>j)&1 ? '#' : '.');
			puts("");
		}
	}
	
	Piece rotate()
	{
		Piece p;
		p.h = w;
		p.w = h;
		fill(p.map, p.map+p.h, 0);
		rep(i, h) rep(j, w)
			p.map[j] |= ((map[i]>>j)&1) << (h-i-1);
		return p;
	}
	
	void calculate()
	{
		area = 0;
		rep(i, h)
			area += __builtin_popcount(map[i]);
		rep(j, w){
			if((map[0]>>j)&1){
				topleft = j;
				break;
			}
		}
	}
	
	// (y, x)にpを重ねて置けるかどうかを返す。
	bool check(int y, int x, const Piece& p)
	{
		if(x<0 || w<x+p.w || h<y+p.h)
			return false;
		rep(i, p.h){
			if(((map[i+y]>>x) & p.map[i]) != p.map[i])
				return false;
		}
		return true;
	}
	
	// (y, x)にpを重ねて置く。
	inline void put(int y, int x, const Piece& p)
	{
		rep(i, p.h)
			map[i+y] |= p.map[i] << x;
	}
	
	// (y, x)に置かえれているpを除去する。
	inline void remove(int y, int x, const Piece& p)
	{
		rep(i, p.h)
			map[i+y] ^= p.map[i] << x;
	}
};



int n, k;
Piece puzzle;
Piece piece[10][4];
int selected[10];

bool search(int d)
{
	++cnt;
	if(d == k)
		return true;
	
	Piece tmp;
	fill(tmp.map, tmp.map+puzzle.h, 0);
	reps(l, d, k) rep(m, 4){
		Piece& p = piece[selected[l]][m];
		rep(i, puzzle.h-p.h+1) rep(j, puzzle.w-p.w+1){
			if(puzzle.check(i, j, p))
				tmp.put(i, j, p);
		}
	}
	if(!equal(puzzle.map, puzzle.map+puzzle.h, tmp.map))
		return false;
	
	rep(l, 4){
		Piece& p = piece[selected[d]][l];
		rep(i, puzzle.h-p.h+1) rep(j, puzzle.w-p.w+1){
			if(puzzle.check(i, j, p)){
				puzzle.remove(i, j, p);
				bool ret = search(d+1);
				puzzle.put(i, j, p);
				if(ret)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	for(;;){
		puzzle.input(true);
		if(puzzle.h == 0)
			break;
		puzzle.trim();
		puzzle.calculate();
		
		scanf("%d", &n);
		rep(i, n){
			piece[i][0].input(false);
			piece[i][0].trim();
			piece[i][0].calculate();
			rep(j, 3){
				piece[i][j+1] = piece[i][j].rotate();
				piece[i][j+1].calculate();
			}
		}
		
		int m;
		scanf("%d", &m);
		map<int, bool> memo;
		rep(i, m){
			scanf("%d", &k);
			int mask = 0;
			rep(j, k){
				scanf("%d", &selected[j]);
				--selected[j];
				mask |= 1 << selected[j];
			}
			
			bool ans;
			if(memo.count(mask))
				ans = memo[mask];
			else{
				int area = 0;
				rep(j, k)
					area += piece[selected[j]][0].area;
				if(area != puzzle.area)
					ans = memo[mask] = false;
				else
					ans = memo[mask] = search(0);
			}
			puts(ans ? "YES" : "NO");
		}
	}
	return 0;
}