#include<bits/stdc++.h>
using namespace std;
int main(){
  char a,b;cin>>a>>b;
  if(a-'0'>b-'0')cout<<'>';
  else if(a-'0'<b-'0')cout<<'<';
  else cout<<'=';}