#include <bits/stdc++.h>
using namespace std;
using namespace std;
string P, S;
int k;
string ans = "0", lef;
int main() {
  getline(cin, P);
  getline(cin, S);
  scanf("%d", &k);
  int n = P.length(), m = S.length();
  int l1 = n % k, l2 = k - n % k, t = n / k;
  bool youjie = false;
  lef.resize(k);
  if (k != 3 && k != 6) {
  }
  for (int x = 0; x <= l1; x++) {
    int y;
    if (t != 0) {
      y = (m - x * (t + 1)) / t;
      if (y * t != (m - x * (t + 1))) continue;
    } else {
      if (x * (t + 1) != k) continue;
      y = 0;
    }
    for (int i = 0; i < k; i++) lef[i] = '0';
    int cnt = x, now = l1 - 1;
    while (cnt && now >= 0) {
      bool ok = true;
      for (int i = now, pos = cnt - 1; i < n && pos < m; i += k, pos += x + y) {
        if (i >= n || pos >= m || P[i] != S[pos]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        lef[now] = '1';
        cnt--;
      } else {
        lef[now] = '0';
      }
      now--;
    }
    if (cnt) continue;
    cnt = y, now = k - 1;
    while (cnt && now >= l1) {
      bool ok = true;
      for (int i = now, pos = x + cnt - 1; i < n && pos < m;
           i += k, pos += x + y) {
        if (i >= n || pos >= m || P[i] != S[pos]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        lef[now] = '1';
        cnt--;
      } else {
        lef[now] = '0';
      }
      now--;
    }
    if (cnt) continue;
    if (youjie) {
      ans = min(ans, lef);
    } else {
      ans = lef;
      youjie = true;
    }
  }
  cout << ans << endl;
  return 0;
};
