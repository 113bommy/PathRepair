#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,t,a;
  float x;
  cin>>n>>x>>t;
  a = ceil(n/x);
  cout<<a*t;
}