#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
int IT_MAX = 1 << 17;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
int n, x, y;
int solve(vector<int> v) {
  int lo = 0, hi = v.size() - 1, ans;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    int l = mid - lo + 1;
    cout << "? " << l << " ";
    for (int i = lo; i <= mid; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
    cin >> ans;
    if (l % 2) {
      if (ans == y)
        hi = mid;
      else
        lo = mid + 1;
    } else {
      if (ans == (x ^ y))
        hi = mid;
      else
        lo = mid + 1;
    }
  }
  return v[lo];
}
int main() {
  cin >> n >> x >> y;
  int k = floor(log2(n));
  bool same[k + 1];
  memset(same, true, sizeof same);
  int p = 0, q = 0, ans;
  for (int i = 0; i <= k; i++) {
    vector<int> v;
    for (int j = 1; j <= n; j++)
      if (j & (1 << i)) v.push_back(j);
    cout << "? " << v.size() << " ";
    fflush(stdout);
    for (int j = 0; j < v.size(); j++) {
      cout << v[j] << " ";
    }
    cout << endl;
    cin >> ans;
    if (v.size() % 2 && ans == y) {
      same[i] = false;
      if (p == 0) p = solve(v);
    } else if (!(v.size() % 2) && ans == (x ^ y)) {
      same[i] = false;
      if (p == 0) p = solve(v);
    }
  }
  for (int i = 0; i <= k; i++) {
    if (same[i] && (p & (1 << i)))
      q = (q | (1 << i));
    else if (!same[i]) {
      if (p & (1 << i))
        q = (q & ~(1 << i));
      else
        q = (q | (1 << i));
    }
  }
  if (p > q) swap(p, q);
  cout << "! " << p << " " << q;
  return 0;
}
