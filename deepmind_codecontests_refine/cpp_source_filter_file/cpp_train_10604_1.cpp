#include<bits/stdc++.h>
using namespace std;
int main() {
	int a=0;
	string s,s1="CODEFESTIVAL2016";
	cin>>s;
	for(int i=0;i<16;i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
}