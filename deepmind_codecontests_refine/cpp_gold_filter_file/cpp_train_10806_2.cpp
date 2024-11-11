#include <bits/stdc++.h>
using namespace std;
int main () {
  int n, v[20], c[20];
  cin>>n;
  for (int i=0;i<n;++i) cin>>v[i];
  for (int i=0;i<n;++i) cin>>c[i];
  int s=0;
  for (int i=0;i<n;++i) {
    if (v[i]>c[i]) s+=v[i]-c[i];
  }
  cout<<s;
  return 0;
}
