#include <bits/stdc++.h>
using namespace std;
const constexpr int INF = 1e9;
const constexpr long long MOD = 1e9 + 7;
const int BITSIZE = 100010;
struct Less {
  bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
    return x.second < y.second;
  }
};
struct More {
  bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
    return x.first > y.first;
  }
};
int bit[100010];
int bit_query(int i) {
  int res = 0;
  for (; i >= 1; i -= i & -i) res = max(res, bit[i]);
  return res;
}
void bit_set(int x, int v) {
  for (; x <= BITSIZE; x += x & -x) {
    bit[x] = max(bit[x], v);
  }
}
int a[1010];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) a[s[i] - 'A']++;
  bool f = true;
  for (int i = 0; i < 26; ++i) {
    if (s[i] || s[i + 32])
      continue;
    else
      f = false;
  }
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
