#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int c=0;
  for(int i=0;i<3;i++){
    if(s[i]=='o')c++;
  }
  cout<<700+c*100<<endl;
}