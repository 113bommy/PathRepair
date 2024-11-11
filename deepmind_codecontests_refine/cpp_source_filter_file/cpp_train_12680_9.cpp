#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int count=0;
  for(int i=0;i<k.size();i++){
    if(s[i]=='o')count++;
  }
  cout<<((count+15-s.size())>=8?"YES":"NO")<<endl;
}