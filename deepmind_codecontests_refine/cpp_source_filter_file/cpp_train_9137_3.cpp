#include<bits/stdc++.h>
using namespace std;

int N,P,pow_10[200001];
string S;
map<int,long long>mp;
long long res;


int main(){
	cin>>N>>P>>S;
	if(P==2){
		for(int i=0;i<N:i++){
			if((S[i]-'0')%2==0)res+=i+1;
		}
		cout<<res<<endl;
		return 0;
	}
	if(P==5){
		for(int i=0;i<N;i++){
			if((S[i]-'0')%5==0)res+=i+1;
		}
		cout<<res<<endl;
		return 0;
	}
	mp[0]++;
	int t=0;
	pow_10[0]=1;
	for(int i=0;i<N;i++){
		pow_10[i+1]=pow_10[i]*10%P;
	}
	for(int i=N-1;i>=0;i--){
		t+=pow_10[N-1-i]*(S[i]-'0');
		t%=P;
		mp[t]++;
	}
	for(auto p:mp){
		res+=p.second*(p.second-1)/2;
	}
	cout<<res<<endl;
}
