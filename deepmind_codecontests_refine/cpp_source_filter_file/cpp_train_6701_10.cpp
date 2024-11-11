#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
vector<int> q, s, t;
bool solve() {
  if (a == 0 or b == 0) return false;
  if (a > k and b > k) return false;
  if (a == 1 and b == 1 and k > 1) return false;
  if (a == k or b == k) return true;
  if (a < k and (k - a) % 2 == 0) return true;
  if (b < k and (k - b) % 2 == 0) return true;
  return false;
}
int main() {
  cin >> n >> k;
  q.resize(n);
  s.resize(n);
  t.resize(n);
  for (int i = 0; i < n; i++) cin >> q[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) t[i] = i + 1;
  while (a <= n + 1 and t != s) {
    a++;
    vector<int> nt(n);
    for (int i = 0; i < n; i++) nt[i] = t[q[i] - 1];
    t = nt;
  }
  for (int i = 0; i < n; i++) t[i] = i + 1;
  while (b <= n + 1 and t != s) {
    b++;
    vector<int> nt(n);
    for (int i = 0; i < n; i++) nt[q[i] - 1] = t[i];
    t = nt;
  }
  bool ans = solve();
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
