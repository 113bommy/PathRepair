#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
  int c=0,ans=0;	
  for(int i=0;i<s.size();i++){
  	if(s[i]=='R')
      c++;
    else{
      ans=max(c,ans);
      c=0;
    }
  }
  cout<<max(ans,c)<<endl;
}