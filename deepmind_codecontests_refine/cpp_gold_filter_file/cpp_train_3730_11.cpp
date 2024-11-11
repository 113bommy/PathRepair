#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int i,x=700;
  
  for(i=0;i<3;i++)
    if(s[i]=='o')x+=100;
  cout<<x;
}
