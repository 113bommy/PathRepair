#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

int N;
int A[11111];

bool prime[11111];
signed main(){
	cin>>N;
	rep(i,N+1)cin>>A[N-i];


	int X=abs(A[N]);

	set<int>s;
	auto f=[&](int p){
		for(int i=0;i<=N;i++)if(A[i]%p)return false;
		return true;
	};

	for(int i=2;i*i<=X;i++){
		if(X%i)continue;
		if(f(i))s.insert(i);
		while(X%i==0)X/=i;
	}
	if(X!=1&&f(X))s.insert(X);

	fill_n(prime,11111,1);
	prime[0]=prime[1]=0;


	auto g=[&](int p){
		for(int i=0;i<p-1&&i<=N;i++){
			int sum=0;
			for(int j=i;j<=N;j+=p-1)sum+=A[j];
			if(sum%p)return false;
		}
		return true;
	};


	for(int i=2;i<11111;i++){
		if(!prime[i])continue;
		if(s.find(i)==s.end()&&g(i)&&A[0]%i==0)s.insert(i);
		for(int j=i+i;j<11111;j+=i)prime[j]=0;
	}
	
	for(auto x:s)cout<<x<<endl;
	return 0;
}