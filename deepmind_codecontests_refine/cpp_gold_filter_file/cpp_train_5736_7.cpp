#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (auto &i : a) cin >> i;
  int b[n];
  int id = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == m) {
      b[i] = 0;
      id = i;
    } else if (a[i] < m) {
      b[i] = -1;
    } else
      b[i] = 1;
  }
  for (int i = 1; i < n; i++) b[i] += b[i - 1];
  map<int, int> ma;
  for (int i = 0; i < id; i++) {
    ma[b[i]]++;
  }
  ma[0]++;
  long long ans = 0;
  for (int i = id; i < n; i++) {
    ans += ma[b[i]] + ma[b[i] - 1];
  }
  cout << ans << "\n";
  return 0;
}
