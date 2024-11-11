// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(ll i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	ll n,m,a,b,p,q;
	cin>>n>>m>>a>>b>>p>>q;
	if(a+b==2){
		ll t=p+q;
		ll T=min(n,m/t);
		ll out=m;
		loop(i,max(0ll,T-10),min(n+1,T+10))
			out=min(out,abs(t*i-m));
		cout<<out<<endl;
		return 0;
	}
	vi A,B;
	ll t=p;
	int co=0;
	while(1){
		A.pb(t);
		if(to_string(t).size()+to_string(a).size()>16)break;
		t*=a;
		if(a==1&&co==40)break;
		co++;
	}
	t=q;
	co=0;
	while(1){
		B.pb(t);
		if(to_string(t).size()+to_string(b).size()>16)break;
		t*=b;
		if(b==1&&co==40)break;
		co++;
	}
	//show1d(A);
	//show1d(B);
	vi in;
	rep(i,min((ll)A.size(),n))
		if(i<B.size()&&A[i]+B[i]<=3*m)in.pb(A[i]+B[i]);
	n=in.size()/2;
	ll N=1<<n;
	vi dp;
	rep(i,N){
		ll sum=0;
		rep(j,n)if(i&1<<j)sum+=in[j];
		if(sum<=3*m)dp.pb(sum);
	}
	sort(all(dp));
	ll nn=in.size()-n;
	N=1<<nn;
	ll out=m;
//	show1d(in);
	rep(i,N){
		ll sum=0;
		rep(j,nn)if(i&1<<j)sum+=in[n+j];
		if(sum>3*m)continue;
		auto it=upper_bound(all(dp),m-sum);
		if(it!=dp.end())out=min(out,abs(*it+sum-m));
		if(it==dp.begin())continue;
		it--;
		out=min(out,abs(*it+sum-m));
	}
//	show1d(dp);
	cout<<out<<endl;
}














