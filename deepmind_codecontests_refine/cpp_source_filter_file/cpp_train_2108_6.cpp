#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    int x = log2(n);
    int q = 1, k = 1, sm = 1;
    if (n == 2) {
      cout << "1\n0\n";
      continue;
    }
    v.push_back(1);
    for (int i = 1; i <= x; ++i) {
      v.push_back(q);
      k += q;
      sm += k;
      q *= 2;
    }
    if (sm == n) {
      cout << v.size() - 1 << '\n';
      for (int i = 1; i < v.size(); ++i) cout << i << ' ';
      cout << '\n';
      continue;
    }
    if (sm > n) {
      sm -= k;
      k -= v.back();
      v.pop_back();
    }
    int l = 0, r = k;
    while (l < r) {
      int m = (l + r) / 2;
      int y = k - v.back();
      int x = sm - k;
      y += m;
      x += y;
      if (x > n) {
        r = m;
        continue;
      }
      if (x == n) {
        v.back() = m;
        break;
      }
      int j = n - x - y;
      if (j <= y && j >= 0) {
        v.back() = m;
        v.push_back(j);
        break;
      } else
        r = m;
    }
    cout << v.size() - 1 << '\n';
    for (int i = 1; i < v.size(); ++i) cout << v[i] << ' ';
    cout << '\n';
  }
  return 0;
}
