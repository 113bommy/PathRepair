#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
#define shosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=(1<<31)-1;
const double pi=acos(-1);

int N,M;
vector<ll> a,b,c,dp,tmp=0;

int main(){
	cin>>N;
	a=vector<ll>(N);
	for(int i=0;i<N;i++) cin>>a[i];
	cin>>M;
	b=vector<ll>(M);
	c=vector<ll>(M);
	for(int i=0;i<M;i++){
		cin>>b[i];
		tmp=max(tmp,b[i]);
	}
	dp=vector<ll>(tmp+1);
	for(int i=0;i<M;i++) cin>>c[i];
	sort(a.begin(),a.end());
	for(int i=1;i<=tmp;i++){
		dp[i]=dp[i-1]+i*(upper_bound(a.begin(),a.end(),i)-lower_bound(a.begin(),a.end(),i));
	}
	for(int i=0;i<M;i++){
		if(dp[b[i]]>=c[i]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}