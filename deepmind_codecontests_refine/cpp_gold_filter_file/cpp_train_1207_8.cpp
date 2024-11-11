#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  sort((a).begin(), (a).end());
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    while (a[i] > k * 2) ++cnt, k <<= 1;
    k = max(k, a[i]);
  }
  cout << cnt << "\n";
}
