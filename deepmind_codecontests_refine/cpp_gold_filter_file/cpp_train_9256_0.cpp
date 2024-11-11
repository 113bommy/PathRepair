#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

#define MP make_pair
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//AOJ 1304
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

set<int> vsi;
int n;

inline int getx(int a){return (a>>25 & 7);}
inline int gety(int a){return (a>>28 & 7);}
inline int getidx(int x, int y){return y*n+x;}
inline int getstate(int a, int x, int y){return ((a>>getidx(x,y))&1);}
inline int setstate(int a, int x, int y, int state){
	if(state){
		return a|(1<<getidx(x,y));
	}else{
		int p=1<<getidx(x,y);
		p = ~p;
		return a&p;
	}
}
inline int setpos(int a, int x, int y){
	int ret=a;
	ret &= ((1<<25)-1);
	ret |= x<<25;
	ret |= y<<28;
	return ret;
}

inline int count(int b){
	int ret = 0;
	REP(i,n)REP(j,n)if(getstate(b,i,j))ret++;
	return ret-1;
}

inline int step(int &b){
	int tb = b;
	int ret = 0;
	int x=getx(b);
	int y=gety(b);
	REP(i,n){
		REP(j,n){
			if(y==i&&x==j)continue;
			int cnt = 0;
			REP(k,8){
				int ny=i+dy[k];
				int nx=j+dx[k];
				if(nx<0 || ny<0 || nx>=n || ny>=n)continue;
				if(getstate(tb,nx,ny))cnt++;
			}
			if(getstate(tb,j,i)){
				if(cnt!=2&&cnt!=3)b=setstate(b,j,i,0);
			}else if(!getstate(tb,j,i)){
				if(cnt==3)b=setstate(b,j,i,1);
			}
		}
	}
	return ret;
}

int main(){
	while(cin>>n, n){
		vsi.clear();
		string b;
		REP(i,n){
			string tmp;
			cin>>tmp;
			b+=tmp;
		}
		int is=0;
		REP(i,n){
			REP(j,n){
				switch(b[i*n+j]){
				case '@':
					is = setpos(is, j, i);
				case '#':
					is |= (1LL<<i*n+j);
					break;
				}
			}
		}
		deque<pair<int, int> > q;
		q.push_back(MP(0,is));
		int ans=-1;
		while(!q.empty()){
			int x,y;
			pair<int, int> tmp=q.front();
			q.pop_front();
			if(EXIST(vsi,tmp.second))continue;
			vsi.insert(tmp.second);
			if(count(tmp.second)==0){
				ans=tmp.first;
				break;
			}
			x = getx(tmp.second);
			y = gety(tmp.second);
			REP(i,8){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<0 || ny<0 || nx>=n || ny>=n || getstate(tmp.second, nx, ny)==1)continue;
				int tb = tmp.second;
				tb=setstate(tb,x,y,0);
				tb=setstate(tb,nx,ny,1);
				tb=setpos(tb,nx,ny);
				step(tb);
				if(EXIST(vsi,tb))continue;
				q.push_back(MP(tmp.first+1, tb));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}