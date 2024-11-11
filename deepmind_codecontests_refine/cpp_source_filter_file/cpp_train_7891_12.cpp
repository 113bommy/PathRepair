#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int n=s.size();
  int a=999;
  for(int i=0;i<n-3;i++){
    int number=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    a=min(a,abs(number-753));}
  cout<<number;}