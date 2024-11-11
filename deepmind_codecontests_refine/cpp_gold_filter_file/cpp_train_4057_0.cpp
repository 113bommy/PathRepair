#include <bits/stdc++.h>
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
#define bit(x) (1<<(x))
using namespace std;

int n,m,p;
int a[15][15];

using R=long double;
R dp[1<<14];

int main(void){
	cin >> n >> m >> p;
	rep(i,m){
		int u,v;
		cin >> u >> v;
		a[u-1][v-1]++;
		a[v-1][u-1]++;
	}

	rep(mask,1,1<<n){
		dp[mask]=1.0;		
		if(__builtin_popcount(mask)==1) continue;
		for(int add=(mask-1)&mask;add>=1;add=(add-1)&mask){
			int root=add^mask;
			if(add<root) break;
			double cur=dp[add];
			rep(i,n)rep(j,n) if(root&bit(i)) if(add&bit(j)) rep(loop,a[i][j]) cur*=1.0*p/100.0; 
			dp[mask]-=cur;	
		}
	}

	cout.precision(20);
	cout << fixed << dp[bit(n)-1] << endl;
	return 0;
}