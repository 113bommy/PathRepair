#include <bits/stdc++.h>
using namespace std;
int a[20];
long long f(int n) {
  int i, L = n, na = 0;
  while (L) {
    a[na++] = 9 - (L % 10);
    L /= 10;
  }
  long long rt = 0;
  for (i = na - 1; i >= 0; i--) {
    rt = 10 * rt + a[i];
  }
  return rt * n;
}
int main() {
  int i, l, r;
  char s[30];
  cin >> l >> r;
  sprintf(s, "%d", r);
  int len = strlen(s);
  int ct = 5;
  for (i = 0; i < len - 1; i++) ct *= 10;
  ct--;
  if (ct >= r)
    cout << f(r) << endl;
  else if (ct <= l)
    cout << f(l) << endl;
  else
    cout << f(ct) << endl;
  return 0;
}
