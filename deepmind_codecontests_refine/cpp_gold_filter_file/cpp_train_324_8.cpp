#include <bits/stdc++.h>
using namespace std;
int n, i, x, oi, ei, r, o[2200], e[2200];
int main() {
  for (cin >> n; i < n; i++) cin >> x, x % 2 ? o[oi++] = x : e[ei++] = x;
  sort(o, o + oi);
  sort(e, e + ei);
  if (oi > ei) swap(o, e), swap(oi, ei);
  for (int i = 0; i < ei - oi - 1; i++) r += e[i];
  cout << r;
}
