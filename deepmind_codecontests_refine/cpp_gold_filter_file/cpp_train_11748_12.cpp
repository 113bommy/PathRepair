#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,x;cin>>x>>a>>b;
  string s;
  if(a>=b) s="delicious";
  if(b>a && b<=x+a) s="safe";
  if(b>x+a) s="dangerous";
  cout<<s<<endl;
}