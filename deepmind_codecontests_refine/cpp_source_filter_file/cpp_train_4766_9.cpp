#include<bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin>>x>>n;
  if(n&1) cout<<"No\n";
  else (n > 4*x || n < 2*x) cout<<"No\n";
  else cout<<"Yes\n";
}