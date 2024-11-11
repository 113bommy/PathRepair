#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int z[600000 + 10 + 600000 + 10], form[600000 + 10][2], n, m, k;
string s, t;
void z_function(string S) {
  int len = S.length();
  S = '$' + S;
  int l, r;
  memset(z, 0, sizeof(z));
  for (int i = 2; i <= len; ++i)
    if (S[i] != S[i - 1])
      break;
    else
      z[2]++;
  l = 2, r = z[2] + 1;
  for (int i = 3; i <= len; ++i) {
    if (i <= r) {
      z[i] = z[i - (l) + 1];
      z[i] = min(z[i], r - i + 1);
      if (z[i] + i - 1 == r) {
        int ite = z[i] + 1;
        for (int j = r + 1; j <= len; ++j) {
          if (S[j] != S[ite++]) break;
          z[i]++;
        }
        l = i, r = i + z[i] - 1;
      }
    } else {
      int ite = 1;
      for (int j = i; j <= len; ++j) {
        if (S[j] != S[ite++]) break;
        z[i]++;
      }
      l = i, r = i + z[i] - 1;
    }
  }
  for (int i = 1; i <= n; ++i) z[i] = z[i + t.length() + 1];
}
set<int> em;
set<int>::iterator ite;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> s >> t;
  z_function(string(t + '&' + s));
  for (int i = 1; i <= n; ++i) {
    if (z[i] == m) {
      for (int j = 1; j <= n; ++j) {
        if (j + k + k - 1 >= i + z[i] - 1) {
          cout << "Yes\n" << j << " " << j + k << '\n';
          return 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) em.insert(i);
  for (int i = 1; i <= n; ++i) {
    if (!z[i]) continue;
    if (i + z[i] - 1 < k) continue;
    int l, r = z[i];
    if (i < k) {
      l = k - i + 1;
    } else {
      l = 1;
    }
    ite = em.lower_bound(l);
    while (ite != em.end() && *ite <= r) {
      form[*ite][0] = i;
      em.erase(ite++);
    }
  }
  em.empty();
  reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
  z_function(string(t + '&' + s));
  for (int i = 1; i <= n; ++i) em.insert(i);
  for (int i = 1; i <= n; ++i) {
    if (!z[i]) continue;
    if (i + z[i] - 1 < k) continue;
    int l, r = z[i];
    if (i < k) {
      l = k - i + 1;
    } else {
      l = 1;
    }
    ite = em.lower_bound(l);
    while (ite != em.end() && *ite <= r) {
      form[*ite][1] = n - i + 1;
      em.erase(ite++);
    }
  }
  for (int i = 1; i <= m - 1; ++i) {
    if (form[i][0] && form[m - i][1] && i <= k && m - i <= k) {
      int L, R;
      R = form[m - i][1] - (m - i) + 1;
      L = form[i][0] + i - 1;
      L -= k;
      L++;
      if (L + k - 1 < R) {
        cout << "Yes\n";
        cout << L << " " << R << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
