#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	int N;
	cin>>N;
	
	map<string,int> zisyo;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		zisyo[i]++;
	}
	
	int saihin=0;
	for(auto z:zisyo){
		saihin=max(saihin,z.second);
	}
	
	for(auto z:zisyo){
		if(z.second==saihin)cout<<z.first<<endl;
	}
	
}
