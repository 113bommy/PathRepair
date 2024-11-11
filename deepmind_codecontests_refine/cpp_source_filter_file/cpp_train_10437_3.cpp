#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  vector<int> *ans = new vector<int>[t];
  for (int it = 0; it < t; ++it) {
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) a[i] == abs(a[i]);
    for (int i = 1; i < n; ++i)
      if (i % 2) a[i] = -a[i];
    for (int i = 0; i < n; ++i) ans[it].push_back(a[i]);
  }
  for (int it = 0; it < t; ++it) {
    for (auto a : ans[it]) cout << a << " ";
    cout << endl;
  }
}
