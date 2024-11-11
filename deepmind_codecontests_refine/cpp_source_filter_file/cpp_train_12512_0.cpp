#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1 << 20;
string s;
int dat[2 * MAX_N - 1]['z' - 'a' + 1];
int teihen = 0;
int init(int n) {
  int a = 1;
  int nw = 2;
  while (a < n) {
    a *= 2;
    teihen += nw;
    nw *= 2;
  }
  teihen -= nw / 2;
  for (int i = 0; 2 * a > i; i++) {
    for (int j = 'a'; 'z' >= j; j++) {
      dat[i][j - 'a'] = 0;
    }
  }
  return a;
}
void initupdate(int k, int a) {
  k += teihen + 1;
  dat[k][a]++;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k][a]++;
  }
}
void update(int k, int a, int b) {
  k += s.size();
  dat[k][a]--;
  dat[k][b]++;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k][a]--;
    dat[k][b]++;
  }
}
bool tmp['z' - 'a' + 1];
void queryinit() {
  for (int i = 'a'; 'z' >= i; i++) tmp[i - 'a'] = false;
}
void query(int a, int b, int k, int l, int r) {
  if (a <= l && r <= b) {
    int ans = 0;
    for (int i = 'a'; 'z' >= i; i++)
      tmp[i - 'a'] = (dat[k][i - 'a'] || tmp[i - 'a']);
  } else if (!(r < a || b < l)) {
    query(a, b, k * 2 + 1, l, (l + r) / 2);
    query(a, b, k * 2 + 2, (l + r) / 2 + 1, r);
  }
}
int main() {
  cin >> s;
  int a = init(s.size());
  for (int i = 0; s.size() > i; i++) initupdate(i, s[i] - 'a');
  int q;
  cin >> q;
  for (int i = 0; q > i; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      int p;
      char w;
      cin >> p >> w;
      p--;
      update(p, s[p] - 'a', w - 'a');
      s[p] = w;
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      query(l, r, 0, 0, a - 1);
      int ans = 0;
      for (int i = 'a'; 'z' >= i; i++)
        if (tmp[i - 'a']) ans++;
      queryinit();
      cout << ans << endl;
    }
  }
  return 0;
}
