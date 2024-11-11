#include <bits/stdc++.h>
using namespace std;
int o[102], p[102], t[102], q[102], s[102], k, n;
void c1(int p[], int q[], int t[]) {
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i)) {
    t[i] = p[q[i]];
  }
}
void c2(int p[], int q[], int t[]) {
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i)) {
    t[q[i]] = p[i];
  }
}
bool cpr(int p[], int q[]) {
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i))
    if (p[i] != q[i]) {
      return false;
    }
  return true;
}
void cpy(int p[], int q[]) {
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i)) q[i] = p[i];
}
int main() {
  cin >> n >> k;
  for (int(i) = 0; (i) < (int)(n); ++(i)) cin >> q[i + 1];
  for (int(i) = 0; (i) < (int)(n); ++(i)) cin >> s[i + 1];
  for (int(i) = 0; (i) < (int)(n); ++(i)) {
    p[i + 1] = i + 1;
    o[i + 1] = i + 1;
  }
  int i;
  if (cpr(p, s)) {
    cout << "NO";
    return 0;
  }
  for (i = 1; i <= k; i++) {
    c1(p, q, t);
    if (cpr(t, s)) break;
    cpy(t, p);
  }
  int l = i;
  for (i = 1; i <= k; i++) {
    c2(o, q, t);
    if (cpr(t, s)) break;
    cpy(t, o);
  }
  int r = i;
  if (l == 1 && r == 1) {
    cout << "NO";
    return 0;
  }
  if (l <= k) {
    if ((k - l) % 2 == 0) {
      cout << "YES";
      return 0;
    }
  }
  if (i <= k) {
    if ((k - i) % 2 == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
