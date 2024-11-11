#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

typedef long long ll;

#define rep(i,x) for(int i = 0 ; i < x ; i ++)
#define pb push_back

int main(){
	int M,N,m0,md,n0,nd;
	scanf("%d%d%d%d%d%d",&M,&N,&m0,&md,&n0,&nd);
	
	vector<int> A;
	priority_queue<int,vector<int>,greater<int>> B;
	rep(i,M){
		A.pb(m0);
		m0 = (m0*58+md)%(N+1);
		//A.pb(m0);
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	rep(i,N){
		B.push(n0);
		n0 = (n0*58+nd)%(M+1);
		//B.push(n0);
	}
	
	ll ret = 0 , res = 0;
	rep(i,M){
		while(B.size() > A[i]){
			res += B.top()-i;
			B.pop();
		}
		while(B.size() > 0 && B.top() == i){
			B.pop();
		}
		ret += B.size();
		ret += min ( res , (ll)A[i]-B.size() );
		res -= min ( res , (ll)A[i]-B.size() );
	}
	cout << ret << endl;
}