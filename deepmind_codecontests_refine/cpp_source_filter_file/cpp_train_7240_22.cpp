#include <bits/stdc++.h>
using namespace std;
long long i, j, m, n, p, q, r, s, a[200005], ss, l, ss1, c;
vector<long long> v;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = n; i >= 1; i--) {
    if (i == n) {
      v.push_back(a[i]);
      s += a[n];
      p = a[n];
    } else if (i == n - 1) {
      v.push_back(a[i] + v[0]);
      s += v[1];
      q = v[1];
    } else {
      l = v.size();
      if (c == 0) {
        ss += q;
        if (l % 2 == 0) v.push_back(a[i] + ss - (s - ss));
        c = 1;
      } else {
        if (l % 2 == 0) {
          ss += (v[l - 1]);
        } else
          ss1 += (v[l - 1] + p);
        if (l % 2 == 0)
          v.push_back(a[i] + ss - (s - ss));
        else
          v.push_back(a[i] + ss1 - (s - ss1));
      }
      s += v[l];
    }
  }
  l = v.size();
  for (i = l - 1; i >= 0; i--) cout << v[i] << " ";
}
