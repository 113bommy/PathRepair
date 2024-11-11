#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator*(long long y,const mint& m){ return m*y; }

int main(){
	int n,m; scanf("%d%d",&n,&m);

	mint dp[2][301][300]; // dp[頂点 0 を含む強連結成分のサイズ][新たに訪れた部分のサイズ] = 場合の数
	dp[0][1][0]=1;
	int cur=0,next=1;
	rep(t,m){
		rep(i,n+1) rep(j,n) dp[next][i][j]=0;

		for(int i=1;i<=t+1;i++) rep(j,n-i+1) if(dp[cur][i][j].to_int()!=0) {
			dp[next][i+j][0]+=i*dp[cur][i][j];       // 0 を含む強連結成分に移動
			dp[next][i][j]+=j*dp[cur][i][j];         // 新たに訪れた j 個の頂点のうちのどれかに移動
			dp[next][i][j+1]+=(n-i-j)*dp[cur][i][j]; // 未到達の頂点に移動
		}
		swap(curr,next);
	}
	printf("%d\n",dp[curr][n][0].to_int());

	return 0;
}
