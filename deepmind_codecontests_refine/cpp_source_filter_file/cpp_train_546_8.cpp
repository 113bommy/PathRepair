#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k = 1, l = 3000, n, a[3100];
  string s[3100];
  vector<int> v;
  vector<string> r;
  cin >> n;
  v.resize(n + 2);
  r.resize(n + 2);
  for (i = 1; i <= n; i++) cin >> s[i] >> a[i];
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
        swap(s[i], s[j]);
      }
  for (i = 1; i <= n; i++)
    if (a[i] > i - 1) {
      cout << "-1";
      return 0;
    }
  for (i = 1; i <= n; i++) {
    v.insert(v.begin() + a[i] + 1, n - i);
    r.insert(r.begin() + a[i] + 1, s[i]);
  }
  for (i = 1; i <= n; i++) cout << r[i] << ' ' << v[i] << endl;
  return 0;
}
