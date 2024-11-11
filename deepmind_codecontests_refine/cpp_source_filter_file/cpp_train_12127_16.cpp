#include <bits/stdc++.h>
using namespace std;
const unsigned M1 = 100007;
const unsigned M2 = 100021;
const unsigned P = 101;
long long fast_pow(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e % 2 == 0) {
    return fast_pow((b * b) % m, e / 2, m) % m;
  }
  return b * fast_pow((b * b) % m, e / 2, m) % m;
}
int main() {
  int n, m;
  cin >> n >> m;
  string p;
  cin >> p;
  if (m == 0) {
    cout << fast_pow(26, p.size(), 1000000007) << '\n';
    return 0;
  }
  vector<int> pos(m);
  for (int i = 0; i < m; ++i) {
    cin >> pos[i];
  }
  int free_s = pos[0] - 1;
  vector<bool> matches(p.size() + 1, true);
  for (int i = 1; i < p.size(); ++i) {
    for (int j = 0; j + i < p.size(); ++i) {
      if (p[j] != p[j + i]) {
        matches[i] = false;
        break;
      }
    }
  }
  for (int i = 1; i < m; ++i) {
    if (pos[i] - (int)p.size() > pos[i - 1]) {
      free_s += pos[i] - pos[i - 1] - p.size();
    } else {
      int diff = pos[i] - pos[i - 1];
      if (matches[diff] == false) {
        cout << "0\n";
        return 0;
      }
    }
  }
  free_s += max(0, (int)(n - pos[m - 1] - p.size() + 1));
  cout << fast_pow(26, free_s, 1000000007ll) << '\n';
}
