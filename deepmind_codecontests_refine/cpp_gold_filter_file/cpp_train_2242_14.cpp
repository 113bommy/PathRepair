#include <bits/stdc++.h>
using namespace std;
string s;
int a[100010];
bitset<100010> bs;
bool dfs(int idx) {
  if (idx >= s.size() || idx < 0) return true;
  if (bs[idx] == 1) return false;
  bs[idx] = 1;
  bool res = false;
  if (s[idx] == '<') {
    res |= dfs(idx - a[idx]);
  } else {
    res |= dfs(idx + a[idx]);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  bs.reset();
  if (dfs(0)) {
    cout << "FINITE" << '\n';
  } else {
    cout << "INFINITE" << '\n';
  }
  return 0;
}
