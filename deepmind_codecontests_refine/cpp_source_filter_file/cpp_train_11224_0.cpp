#include <bits/stdc++.h>
using namespace std;

int n;
int a[200000];

bool ok(int kind) {
  map<int, int> mp;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] < a[i]) continue;
    if (kind == 1) return false;
    
    int k = a[i];
    while (mp[k] == kind - 1) {
      mp[k] = 0;
      --k;
    }
    if (k <= 0) return false;
    ++mp[k];
    
    mp.erase(mp.upper_bound(idx), mp.end());
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int lo = 0;
  int hi = n;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi << endl;
}