#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  int a=stoi(s+t);
  int b=(int)(sqrt(a)+1e-12);
  if(b*b==a)puts("Yes");
  else puts("No");
}