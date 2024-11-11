#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int a=1900*m+100*(n-m)<<endl;
  int p=pow(2,m);
  int ans=a*p;
  cout<<ans<<endl;
}
