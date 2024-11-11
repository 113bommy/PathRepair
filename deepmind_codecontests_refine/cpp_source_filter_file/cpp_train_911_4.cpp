#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 505;
mt19937 rng(time(0));

int n, x, y, a[N*n], dp[N][N], v[N][N];
int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};

void update(int x, int y){
	v[x][y] = 0;
	queue<ar2> Q;
	Q.push({x, y});
	while(!Q.empty()){
		ar2 ele = Q.front();
		Q.pop();
		int x = ele[0], y = ele[1];
		rep(i,0,3){
			int x1 = x + dx[i], y1 = y + dy[i];
			if(dp[x][y] + v[x][y] < dp[x1][y1]){
				dp[x1][y1] = dp[x][y] + v[x][y];
				Q.push({x1, y1});
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n*n) scanf("%d",a+i);
	
	rep(i,1,n) rep(j,1,n)
		dp[i][j] = min(min(i-1, n-i), min(j-1, n-j)),
		v[i][j] = 1;
	
	int ans = 0;
	rep(q,1,n*n){
		x = a[q] - 1;
		y = x % n + 1, x = x / n + 1;
		
		ans += dp[x][y];
		update(x, y);		
	}
	cout<<ans<<endl;
	return 0;
}