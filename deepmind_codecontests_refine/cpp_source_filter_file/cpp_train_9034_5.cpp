#include<bits/stdc++.h>

using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int ans=0;
	for(int i=0;i<3;i++){
		if(s[i]==s[t]) ans++;
	}
	cout<<ans;
	return 0;
}