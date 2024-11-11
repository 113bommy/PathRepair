clude <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=5000+5;
const ll oo=1e18+5;
const ll mod=998244353;
 
int n;
int dp[2005][2005];
 
void max_self(int& a,int b){
	if(b>a) a=b;
}
 
void update(int i,int j,int val){
	max_self(dp[i][j],val);
	max_self(dp[j][i],val);
	max_self(dp[i][n],val);
	max_self(dp[n][i],val);
	max_self(dp[j][n],val);
	max_self(dp[n][j],val);
	max_self(dp[n][n],val);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int n3=n*3;
	vector<int> a(n3);
	for(int& x:a) cin>>x,--x;
	int m=n+1;
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j) dp[i][j]=-INF;
	}
	update(a[0],a[1],0);
	int add=0;
	for(int i=2;i<n3-1;i+=3){
		int x=a[i],y=a[i+1],z=a[i+2];
		if(x==y&&y==z){
			++add;
			continue;
		}
		vector<tuple<int,int,int>> vec;
		for(int times=0;times<3;++times){
			{
				for(int aa=0;aa<m;++aa){
					int now=dp[aa][n];
					if(y==z){
						max_self(now,dp[aa][y]+1);
					}
					vec.emplace_back(aa,x,now);
				}
			}
			{
				int now=max(dp[n][n],dp[z][z]+1);
				vec.emplace_back(x,y,now);
			}
			swap(x,y);
			swap(y,z);
		}
		for(tuple<int,int,int> x:vec){
			int i,j,val;
			tie(i,j,val)=x;
			update(i,j,val);
		}
	}
	int ans=dp[n][n];
	int l=a[n3-1];
	max_self(ans,dp[l][l]+1);
	ans+=add;
	cout<<ans;
	return 0;
}