#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int N;
	string S;
	cin>>N>>S;
	vector<long long> rgb(3,0);
	for(int i=0;i<N;i++){
		if(S[i]=='R') rgb[0]++;
		if(S[i]=='G') rgb[1]++;
		if(S[i]=='B') rgb[2]++;
	}
	long long ans=rgb[0]*lgb[1]*lgb[2];
	
	for(int j=0;j<N;j++){
		for(int i=0;i<j;i++){
			long long k=2*j-i;
			if(k>=N) continue;
			if(S[i]==S[j]||S[j]==S[k]||S[k]==S[i]) continue;
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}