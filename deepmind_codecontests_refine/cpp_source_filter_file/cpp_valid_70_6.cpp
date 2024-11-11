#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m, x, t, l, k, tc, c;
  cin >> tc;
  for (int ts = 1; ts <= tc; ts++) {
    string s, s1 = "", s2 = "", s3 = "";
    cin >> s;
    map<int64_t, char> p;
    map<char, int64_t> q;
    map<char, int64_t> r;
    map<char, int64_t> d;
    int64_t a[s.size() + 10];
    l = 0, k = 0;
    for (int i = 0; i < s.size(); i++) {
      q[s[i]]++;
    }
    for (char i = 'a'; i <= 'z'; i++) {
      for (int j = s.size() - 1; j >= 0; j--) {
        if (s[j] == i) {
          a[l++] = j;
          p[j] = i;
          break;
        }
      }
    }
    if (l == 1) {
      cout << s << " " << s[0] << endl;
      continue;
    }
    sort(a, a + l);
    c = 0;
    k = 0;
    for (char i = 0; i < l; i++) {
      if ((q[p[a[i]]] % (i + 1)) != 0) {
        cout << "-1\n";
        c = 1;
        break;
      }
      x = q[p[a[i]]] / (i + 1);
      r.clear();
      char ch = p[a[i]];
      for (int j = 0; j < n; j++) {
        if (s[j] == ch) {
          r[s[j]]++;
          if (r[s[j]] == x) {
            d[s[j]] = x;
            k = max(k, (int64_t)j);
            break;
          }
        }
      }
    }
    if (c == 1) {
      continue;
    }
    q.clear();
    for (int i = 0; i <= k; i++) {
      q[s[i]]++;
      s1 += s[i];
      if (q[s[i]] > d[s[i]]) {
        c = 1;
        break;
      }
    }
    if (c == 1) {
      cout << "-1\n";
      continue;
    }
    s3 = s1;
    q.clear();
    for (int i = 0; i < l; i++) {
      s2 += p[a[i]];
      q[p[a[i]]] = -1;
      for (int j = 0; j < s1.size(); j++) {
        if (q[s[j]] != -1) {
          s3 += s1[j];
        }
      }
    }
    if (s3 == s) {
      cout << s1 << " " << s2 << endl;
    } else {
      cout << "-1\n";
    }
  }
}
