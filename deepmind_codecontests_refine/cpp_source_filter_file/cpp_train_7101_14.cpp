#include <bits/stdc++.h>
using namespace std;
string s;
long long last[30], pred[200010];
char ch;
long long a[1000100], aa[1000100];
char b[1000100];
long long m, mm, t, j, n, k;
int main() {
  cin >> s >> k;
  s = " " + s;
  n = s.size() - 1;
  if (1LL * (n) * (n + 1) / 2LL < k) {
    cout << "No such line." << endl;
    return 0;
  }
  memset(last, 0, sizeof(last));
  for (int i = 1; i <= n; i++) {
    pred[i] = last[s[i]];
    last[s[i]] = i;
  }
  t = 0;
  ch = ' ';
  for (char c = 'a'; c <= 'z'; c++) {
    j = last[c];
    t = 0;
    while (j > 0) {
      t += (n - j + 1);
      if (k <= t) break;
      j = pred[j];
    }
    if (k <= t) {
      cout << c;
      ch = c;
      break;
    }
    k -= t;
  }
  m = 0;
  j = last[ch];
  while (j > 0) {
    m++;
    a[m] = j;
    j = pred[j];
  }
  for (int len = 2; len <= n; len++) {
    if (m >= k) break;
    k -= m;
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= m; i++) {
      if (a[i] + len - 1 <= n) {
        b[i] = s[a[i] + len - 1];
        pred[i] = last[b[i]];
        last[b[i]] = i;
      } else
        b[i] = ' ';
    }
    ch = ' ';
    for (char c = 'a'; c <= 'z'; c++) {
      j = last[c];
      t = 0;
      while (j > 0) {
        t += (n - a[j] - len + 2);
        if (k <= t) break;
        j = pred[j];
      }
      if (k <= t) {
        cout << c;
        ch = c;
        break;
      }
      k -= t;
    }
    mm = 0;
    for (int i = 1; i <= m; i++) {
      if (b[i] == ch) {
        mm++;
        aa[mm] = a[i];
      }
    }
    m = mm;
    for (int i = 1; i <= m; i++) a[i] = aa[i];
  }
  return 0;
}
