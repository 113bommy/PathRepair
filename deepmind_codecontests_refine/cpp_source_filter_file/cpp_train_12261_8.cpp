#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int count = 0;
	int ans = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='R)
		count++;
		else
		count=0;
		ans=max(ans,count);
}
cout<<ans;
}
