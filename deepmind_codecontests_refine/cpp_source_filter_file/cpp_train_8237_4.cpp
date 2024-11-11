#include <bits/stdc++.h>
using namespace std;
const int mn = 5e5 + 100;
const int inf = 1e9;
const int mod = 1e9 + 7;
int f[mn], n;
string s, t, tp;
int tedad[2][2], t0, t1;
void kmp() {
  f[0] = f[1] = 0;
  for (int i = 1; i <= n; i++) {
    int k = f[i];
    while (k != 0 && t[i] != t[k]) {
      k = f[k];
    }
    if (t[k] == t[i]) {
      k++;
    }
    f[i + 1] = k;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << setprecision(30);
  cin >> s >> t;
  n = t.size();
  for (char i : s) {
    tedad[0][i - '0']++;
  }
  for (char i : t) {
    tedad[1][i - '0']++;
  }
  kmp();
  if (tedad[0][0] < tedad[1][0] || tedad[0][1] < tedad[1][0]) {
    cout << s << "\n";
    return 0;
  }
  for (int i = 0; i < f[n]; i++) {
    tp += t[i];
    if (t[i] == '0') {
      t0++;
    } else {
      t1++;
    }
  }
  if (f[n] == 0) {
    tp = t;
    t0 = tedad[1][0];
    t1 = tedad[1][1];
  }
  cout << t;
  tedad[0][0] -= tedad[1][0];
  tedad[0][1] -= tedad[1][1];
  while (tedad[0][0] >= t0 && tedad[0][1] >= t1) {
    cout << tp;
    tedad[0][0] -= t0;
    tedad[0][1] -= t1;
  }
  for (int i = 0; i < tedad[0][0]; i++) {
    cout << '0';
  }
  for (int i = 0; i < tedad[0][1]; i++) {
    cout << '1';
  }
  cout << "\n";
  return 0;
}
