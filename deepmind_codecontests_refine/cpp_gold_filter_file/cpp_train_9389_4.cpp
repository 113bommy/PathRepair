#include <bits/stdc++.h>
using namespace std;
string s;
int n, aa, a[101010], b[101010], c[101010], d[101010];
vector<pair<int, int> > v;
long long ans, sum;
bool cmp(int x, int y) {
  if (c[x] != c[y]) {
    return c[x] < c[y];
  }
  x += aa;
  y += aa;
  if (x < n && y < n) {
    return c[x] < c[y];
  } else {
    return x > y;
  }
}
int main() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    b[i] = i;
    c[i] = s[i];
  }
  for (aa = 1;; aa *= 2) {
    sort(b, b + n, cmp);
    for (int i = 0; i < n - 1; i++) {
      d[i + 1] = d[i] + cmp(b[i], b[i + 1]);
    }
    for (int i = 0; i < n; i++) {
      c[b[i]] = d[i];
    }
    if (d[n - 1] == n - 1) {
      break;
    }
  }
  int nw = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] != n - 1) {
      for (int j = b[c[i] + 1]; s[i + nw] == s[j + nw];) {
        nw++;
      }
      a[c[i]] = nw;
      nw = max(nw - 1, 0);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int t = 1;
    while (v.size() && v.back().first >= a[i]) {
      sum -= v.back().first * v.back().second;
      t += v.back().second;
      v.pop_back();
    }
    sum += a[i] * t;
    ans += sum;
    v.push_back(make_pair(a[i], t));
  }
  ans += 1ll * n * (n + 1) / 2;
  cout << ans << endl;
  return 0;
}
