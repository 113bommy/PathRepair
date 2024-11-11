#include<iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N,K;
const long long INF=100000000000LL;
long long a[20];
long long reg(int n,int k,long long t){
	if(k==K)return 0;
	if(n==N)return INF;
	if(a[n]>t)return reg(n+1,k+1,a[n]);
	long long was=INF;
	was=min(was,t+1-a[n]+reg(n+1,k+1,t+1));
	was=min(was,reg(n+1,k,t));
	//cout<<n<<" "<<k<<" "<<t<<" "<<was<<endl;
	return was;
}
int main(){
//	memset(dp,-1,sizeof(dp));
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	cout<<reg(1,1,a[0])<<endl;
	return 0;
}
