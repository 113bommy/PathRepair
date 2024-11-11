#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int a[maxn], b[maxn], cnt[maxn], cnt2[maxn];
bool u[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < (int)t.size(); ++i) {
    bool fl = false;
    for (int j = 0; j < (int)s.size(); ++j) {
      if (t[i] == s[j]) fl = true;
    }
    if (!fl) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < (int)s.size(); ++i) {
    int c = 0, cur = i - 1;
    for (int j = 0; j < (int)t.size(); ++j) {
      cur++;
      if (cur == (int)s.size()) {
        cur = 0;
        c++;
      }
      while (s[cur] != t[j]) {
        cur++;
        if (cur == (int)s.size()) {
          cur = 0;
          c++;
        }
      }
    }
    a[i] = cur;
    b[i] = c;
  }
  int cur = 0;
  while (s[cur] != t[0]) cur++;
  int c = 0, k = 0;
  u[cur] = true;
  while (true) {
    if (c + b[cur] >= n) {
      cout << k / m << endl;
      return 0;
    }
    k++;
    c += b[cur];
    cur = a[cur];
    cur++;
    if (cur == (int)s.size()) {
      cur = 0;
      c++;
    }
    if (u[cur]) {
      break;
    }
    u[cur] = true;
    cnt[cur] = k;
    cnt2[cur] = c;
  }
  cerr << "c"
       << " = " << c << ' ';
  ;
  cerr << "k"
       << " = " << k << ' ';
  ;
  cerr << endl;
  int x = k - cnt[cur];
  int y = c - cnt2[cur];
  k -= x;
  c -= y;
  k += x * ((n - c - 1) / y);
  c += y * ((n - c - 1) / y);
  cerr << "c"
       << " = " << c << ' ';
  ;
  cerr << "k"
       << " = " << k << ' ';
  ;
  cerr << endl;
  while (true) {
    if (c + b[cur] >= n) {
      cout << k / m << endl;
      return 0;
    }
    k++;
    c += b[cur];
    cur = a[cur];
    cur++;
    if (cur == (int)s.size()) {
      cur = 0;
      c++;
    }
  }
  return 0;
}
