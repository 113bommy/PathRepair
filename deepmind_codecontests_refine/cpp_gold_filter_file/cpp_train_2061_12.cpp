#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((i+1)%2==1&&s[i]=='L'){
			cout<<"No"<<endl;
			return 0;
		}
		if((i+1)%2==0&&s[i]=='R'){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0; }