#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n,m,k;
vl a;

vl dp;

int main(){
	cin>>n>>m>>k;
	a=dp=vl(n);
	for(int i=0;i<n;i++) cin>>a[i];
	dp=a;
	for(int i=1;i<k;i++){
		deque<int> q;
		vl DP(n);
		for(int j=0;j<n;j++){
			if(j>=i) DP[j]=dp[q.front()]+a[j]*(i+1);
			while(!q.empty()&&dp[q.back()]<=dp[j]) q.pop_back();
			q.push_back(j);
			if(!q.empty()&&q.front()==j-m) q.pop_front();
		}
		dp=DP;
	}
	ll res=-1;
	for(int i=0;i<n;i++) res=max(res,dp[i]);
	cout<<res<<endl;
}