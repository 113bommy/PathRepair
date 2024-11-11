#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++) cin >> b[i];
  unordered_map<int, int> mp;
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    mp[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    mpp[b[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mpp.find(a[i] + b[j]) == mpp.end() &&
          mp.find(a[i] + b[j]) == mp.end()) {
        cout << a[i] << " " << b[j];
        return 0;
      }
    }
  }
  return 0;
}
