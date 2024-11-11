// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int N,H[17],W[17];
int c[5][5];
int dist[1<<16];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	rep(i,N)cin>>H[i]>>W[i];
	rep(i,4)rep(j,4){
		char C;
		cin>>C;
		c[i][j] = C=='R' ? 0 : C=='G' ? 1 : 2;
	}
	rep(i,1<<16)dist[i] = INF;
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	while(sz(Q)){
		int mask = Q.front(); Q.pop();
		if(mask == (1<<16)-1){
			return cout<<dist[mask]<<endl,0;
		}
		int done[4][4][4][4][3] = {};
		rep(i,N){
			rep2(y,-H[i]+1,4)rep2(x,-W[i]+1,4)rep(color,3){
				int nmask = mask;
				int y0 = max(0, y);
				int x0 = max(0, x);
				int y1 = min(3, y+H[i]-1);
				int x1 = min(3, x+W[i]-1);
				if(done[y0][x0][y1][x1][color])continue;
				done[y0][x0][y1][x1] = 1;
				rep(ii,H[i])rep(jj,W[i]){
					int Y = y+ii, X = x+jj;
					if(Y<0 || Y>=4 || X<0 || X>=4)continue;
					if(c[Y][X] == color) nmask |= 1<<Y*4+X;
					else nmask &= ~(1<<Y*4+X);
				}
				if(dist[nmask] > dist[mask] + 1){
					dist[nmask] = dist[mask] + 1;
					Q.push(nmask);
				}
			}
		}
	}
}