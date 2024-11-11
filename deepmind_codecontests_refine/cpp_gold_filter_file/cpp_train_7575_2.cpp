#include <bits/stdc++.h>
using namespace std;


void solve(){
string s;
cin>>s;
for(auto i=0;i<s.size();i++){
	if(s[i]=='?'){
		s[i]='D';
	}
	
}
cout<<s;
}



int main() {


	solve();


}