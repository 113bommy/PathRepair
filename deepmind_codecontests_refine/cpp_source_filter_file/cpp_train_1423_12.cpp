#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 1;
  cin >> n;
  map<int, int> m;
  vector<int> a(n), p, is_p(10001, 1), t;
  vector<vector<int>> pv;
  for (int i = 2; i <= 10000; i++)
    if (is_p[i]) {
      p.push_back(i);
      for (int j = i * i; j <= 10000; j += i) is_p[j] = 0;
    }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i]) continue;
    int ab = abs(a[i]), temp = 1;
    for (int tp : p)
      if (ab % tp == 0) {
        int ct = 0;
        while (ab % tp == 0) ct++, ab /= tp;
        if (ct & 1) temp *= tp;
      }
    if (ab != 1) temp *= ab;
    if (a[i] < 0) temp *= -1;
    if (m.find(temp) == m.end()) m[temp] = cnt++;
    a[i] = m[temp];
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int cur = 0;
    vector<int> num(cnt);
    for (int j = i; j < n; j++) {
      if (!a[j] && ++num[a[j]] == 1) cur++;
      ans[max(0, cur - 1)]++;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cin >> n;
}
