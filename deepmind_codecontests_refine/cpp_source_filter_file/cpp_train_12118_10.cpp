#include <bits/stdc++.h>
long long h, i, j, k, l, n, m, x;
long long d[10001], e[10001];
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  vector<int> def, atk, v;
  for (i = 1; i <= n; i++) {
    string s;
    cin >> s >> k;
    if (s == "ATK")
      atk.push_back(k);
    else
      def.push_back(k);
  }
  for (i = 1; i <= m; i++) cin >> k, v.push_back(k);
  k = 0;
  while (true) {
    sort(v.begin(), v.end(), greater<int>());
    sort(atk.begin(), atk.end(), greater<int>());
    if (!atk.size()) break;
    for (i = 0; i < min(v.size(), atk.size()); i++)
      if (v[i] < atk[i]) break;
    if (i != min(v.size(), atk.size())) {
      atk.erase(atk.begin() + i);
    } else {
      d[0] = 0, e[0] = 0;
      sort(atk.begin(), atk.end());
      for (i = 1; i <= min(v.size(), atk.size()); i++) {
        d[i] = v[i - 1] + d[i - 1], e[i] = atk[i - 1] + e[i - 1];
        k = max(k, d[i] - e[i]);
      }
      x = true;
      break;
    }
  }
  if (!x && def.size() < n) {
    cout << 0;
    return 0;
  }
  if (x && def.size() + atk.size() < n) {
    cout << k;
    return 0;
  }
  while (true) {
    if (!def.size() && v.size()) break;
    if (!v.size()) {
      cout << k;
      return 0;
    }
    sort(v.begin(), v.end());
    sort(def.begin(), def.end());
    for (i = 0; i < v.size(); i++) {
      for (j = 0; j < def.size(); j++)
        if (v[i] > def[j]) {
          v.erase(v.begin() + i);
          def.erase(def.begin() + j);
          goto f;
        }
    }
  f:;
    if (i == v.size()) v.clear();
  }
  while (true) {
    if (!atk.size() && !v.size()) {
      cout << max(l, k);
      return 0;
    }
    if (!v.size()) {
      cout << k;
      return 0;
    }
    if (!atk.size()) break;
    sort(v.begin(), v.end());
    sort(atk.begin(), atk.end());
    for (i = 0; i < v.size(); i++) {
      for (j = 0; j < atk.size(); j++)
        if (v[i] >= atk[j]) {
          l += v[i] - atk[j];
          v.erase(v.begin() + i);
          atk.erase(atk.begin() + j);
          goto c;
        }
    }
  c:;
    if (i == v.size()) v.clear();
  }
  for (i = 0; i < v.size(); i++) l += v[i];
  cout << max(l, k);
  return 0;
}
