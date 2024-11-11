#include <bits/stdc++.h>
using namespace std;
const int maxn = 2048;
string s[maxn];
int h[maxn], n, k;
int lcp(string a, string b) {
  int k = 0;
  while (k < a.size() && k < b.size() && a[k] == b[k]) k++;
  return k;
}
vector<int> solve(int l, int r) {
  if (l == r) {
    return vector<int>(2, 0);
  }
  int m = l;
  for (int i = l + 1; i + 1 <= r; ++i) {
    if (h[i] > h[m]) {
      m = i;
    }
  }
  vector<int> a = solve(l, m), b = solve(m + 1, r);
  vector<int> ret(r - l + 2, -(1 << 30));
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      ret[i + j] = max(ret[i + j], a[i] + b[j] + h[m] * i * j);
    }
  }
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s, s + n);
  for (int i = 0; i + 1 < n; ++i) {
    h[i] = lcp(s[i], s[i + 1]);
  }
  vector<int> ret = solve(0, n - 1);
  cout << ret[k] << endl;
  return 0;
}
