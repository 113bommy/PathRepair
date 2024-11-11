#include<bits/stdc++.h>
using namepsace std;
int main(){
  string s;
  cin>>s;
  int l=s.size(), count=0;
  for(int i=0;i<l/2;i++){
  if(s[i]!=s[l-i])
    count++;
  }
  cout<<count<<endl;
return 0;
}