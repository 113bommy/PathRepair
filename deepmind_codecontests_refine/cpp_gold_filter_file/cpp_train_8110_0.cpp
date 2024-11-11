// g++ -std=c++11 temp.cpp
#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Rep(i,n) For(i,0,n)
#define Each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3;

#define MAX_N 100

int N;
int board[MAX_N*2][MAX_N*2];
int h[MAX_N*2][MAX_N*2];

struct dice{
	int x, xx, y, yy, z, zz;
};
dice d;

void rotation(int *a, int *b, int *c, int *d){
	int t = *a;
	*a = *b;
	*b = *c;
	*c = *d;
	*d = t;
}
void roll_x(){ rotation(&d.x,&d.z,&d.xx,&d.zz); }
void roll_xx(){ rotation(&d.x,&d.zz,&d.xx,&d.z); }
void roll_y(){ rotation(&d.y,&d.z,&d.yy,&d.zz); }
void roll_yy(){ rotation(&d.y,&d.zz,&d.yy,&d.z); }
void roll_xy(){ rotation(&d.x,&d.y,&d.xx,&d.yy); }
void make_dice(int t, int f){
	d.x = 3; d.xx = 4; d.y = 5; d.yy = 2; d.z = 1; d.zz = 6;
	Rep(i,4){
		if(d.z == t) break;
		roll_x();
	}
	Rep(i,4){
		if(d.z == t) break;
		roll_y();
	}
	while(d.x != f){ roll_xy(); }
}

int main(int argc, char const *argv[])
{
	while(1){
		cin >> N;
		if(N == 0) break;
		Rep(i,MAX_N*2)Rep(j,MAX_N*2){
			board[i][j] = 0;
			h[i][j] = 0;
		}
		Rep(i,N){
			int t, f;
			scanf("%d %d", &t, &f);
			make_dice(t,f);
			int dx = 100, dy = 100;
			while(1){
				int maxx = 0;
				if(d.x >= 4 && h[dx][dy] > h[dx+1][dy]){
					if(maxx < d.x) maxx = d.x;
				}
				if(d.y >= 4 && h[dx][dy] > h[dx][dy+1]){
					if(maxx < d.y) maxx = d.y;
				}
				if(d.xx >= 4 && h[dx][dy] > h[dx-1][dy]){
					if(maxx < d.xx) maxx = d.xx;
				}
				if(d.yy >= 4 && h[dx][dy] > h[dx][dy-1]){
					if(maxx < d.yy) maxx = d.yy;
				}
				if(maxx == 0) break;
				if(maxx == d.x){
					roll_x(); dx++;
				}else if(maxx == d.y){
					roll_y(); dy++;
				}else if(maxx == d.xx){
					roll_xx(); dx--;
				}else if(maxx == d.yy){
					roll_yy(); dy--;
				}
			}
			h[dx][dy]++;
			board[dx][dy] = d.z;
		}
		int res[7];
		Rep(i,7) res[i] = 0;
		Rep(i,MAX_N*2)Rep(j,MAX_N*2){
			res[board[i][j]]++;
		}
		cout << res[1];
		For(i,2,7) cout << " " << res[i];
		cout << endl; 
	}
	return 0;
}