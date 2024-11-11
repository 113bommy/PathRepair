#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	int ans=1e9,tmp1=0,tmp0=0;
	for(int i=0;i<26;i++){
	  char c='a'+i;
	  tmp1=0;tmp0=0;
	for(int j=0;j<s.size();j++){  
		if(s[j]!=c)tmp0++;
		 else{
			tmp1=max(tmp1,tmp0);tmp0=0;
			}
	}
	tmp1=max(tmp1,tmp0);
	ans=min(ans,tmp1);
	}
	cout<<ans<<endl;
}