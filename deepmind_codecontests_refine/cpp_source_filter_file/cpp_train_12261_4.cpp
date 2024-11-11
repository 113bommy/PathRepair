#include<bits/stdc++.h> 
using namespace std;
int main(){
string s;cin>>s;
  int c=0;int maxi=0;
  for(int i=0;i<(int)s.size;++i){
if(s[i]=='S')c=0;
    else ++c;
    maxi=max(maxi,c);
  }
  maxi=max(maxi,c);
  cout<<maxi<<endl;
}