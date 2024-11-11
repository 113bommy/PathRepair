#include <bits/stdc++.h>
using namespace std;

int main() {
  int l = 1, r = 0, n, k;

  cin >> n >> k;

  vector<int> a(n,0);
  
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    r = max(r, a[i]);
  }

  while(r > l) {
    int x = l + (r - l) / 2, c = 0;

    for(int i = 0; i < n; i++)
      c += (a[i] - 1) / x;
    
    if(c <= k)
      r = x;
    else
      l = x + 1;
  }

  cout << r;

  return 0;
}