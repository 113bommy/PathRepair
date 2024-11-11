#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int i, j, x, n, a, b, m, t, pos, l, tot, st, en;
  cin >> a >> b >> n;
  vector<long long int> v, sam;
  v.push_back(0);
  v.push_back(a);
  for (i = 2; i <= 1000002; i++) {
    x = a + (i - 1) * b;
    v.push_back(v[i - 1] + x);
  }
  for (i = 1; i <= n; i++) {
    cin >> l >> t >> m;
    if (t < v[l] - v[l - 1]) {
      cout << "-1" << endl;
      continue;
    }
    pos = 1;
    tot = t * m;
    st = 1;
    en = 1000002;
    while (en - st + 1 > 2) {
      x = (en - st + 1) / 2;
      if (v[st + x] - v[l - 1] <= tot && v[st + x] - v[st + x - 1] <= t) {
        pos += x;
        st += x;
      } else {
        en = st + x;
      }
    }
    cout << pos << endl;
  }
}
