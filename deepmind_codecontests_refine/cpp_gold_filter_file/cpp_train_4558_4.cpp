#include <bits/stdc++.h>
using namespace std;

long long n, ans;

int main() {
  cin >> n;
  ans = (n+2)*(n+1)*(n)/6;
  for(int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    if(u > v) swap(u, v);
    ans -= u*(n+1-v);
  }
  cout << ans << endl;
  
  return 0;
}