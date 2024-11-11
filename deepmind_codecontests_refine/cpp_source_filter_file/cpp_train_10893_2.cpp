#include <bits/stdc++.h>
using namespace std;
char s[1001][7];
int n, a[30], p, m, ch, j, mn, mx, val, o;
long long sum;
struct chestie {
  int c, fr, ok, nr;
} v[30];
int pow(int N, int E);
bool comp(chestie X, chestie Y);
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin.get();
    cin >> s[i];
    m = strlen(s[i]);
    for (int j = 0; j < m; j++) {
      ch = s[i][j] - 'a';
      if (ch > mx) mx = ch;
      if (v[ch].fr == 0) o++;
      v[ch].fr += (pow(10, (m - j - 1)));
      v[ch].c = ch;
      if (j == 0 && m > 1) v[ch].ok = 1;
    }
  }
  sort(v + 0, v + mx + 1, comp);
  val = 1;
  j = 1;
  for (int i = 0; i < o; i++) {
    if (v[i].ok || j == 0) {
      v[i].nr = val;
      sum += (v[i].fr * val);
      val++;
    } else if (j)
      v[i].nr = 0, j = 0, a[v[i].c] = 0;
  }
  cout << sum;
  return 0;
}
int pow(int N, int E) {
  int R = 1;
  while (E) R = R * N, E--;
  return R;
}
bool comp(chestie X, chestie Y) {
  if (X.fr > Y.fr) return 1;
  if (X.fr < Y.fr) return 0;
  if (X.c < Y.c) return 1;
  return 0;
}
