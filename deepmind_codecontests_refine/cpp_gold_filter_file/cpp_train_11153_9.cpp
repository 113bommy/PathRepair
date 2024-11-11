#include <bits/stdc++.h>
using namespace std;
int n, ok, i, nrmin, nr;
char s[200010];
int main() {
  cin >> n;
  nr = 0;
  cin >> s;
  for (i = 0; i < n; i = i + 3)
    if (s[i] != 'R') nr++;
  for (i = 1; i < n; i = i + 3)
    if (s[i] != 'G') nr++;
  for (i = 2; i < n; i = i + 3)
    if (s[i] != 'B') nr++;
  nrmin = nr;
  ok = 1;
  nr = 0;
  for (i = 0; i < n; i = i + 3)
    if (s[i] != 'R') nr++;
  for (i = 1; i < n; i = i + 3)
    if (s[i] != 'B') nr++;
  for (i = 2; i < n; i = i + 3)
    if (s[i] != 'G') nr++;
  if (nr < nrmin) {
    nrmin = nr;
    ok = 2;
  }
  nr = 0;
  for (i = 0; i < n; i = i + 3)
    if (s[i] != 'G') nr++;
  for (i = 1; i < n; i = i + 3)
    if (s[i] != 'R') nr++;
  for (i = 2; i < n; i = i + 3)
    if (s[i] != 'B') nr++;
  if (nr < nrmin) {
    nrmin = nr;
    ok = 3;
  }
  nr = 0;
  for (i = 0; i < n; i = i + 3)
    if (s[i] != 'G') nr++;
  for (i = 1; i < n; i = i + 3)
    if (s[i] != 'B') nr++;
  for (i = 2; i < n; i = i + 3)
    if (s[i] != 'R') nr++;
  if (nr < nrmin) {
    nrmin = nr;
    ok = 4;
  }
  nr = 0;
  for (i = 0; i < n; i = i + 3)
    if (s[i] != 'B') nr++;
  for (i = 1; i < n; i = i + 3)
    if (s[i] != 'R') nr++;
  for (i = 2; i < n; i = i + 3)
    if (s[i] != 'G') nr++;
  if (nr < nrmin) {
    nrmin = nr;
    ok = 5;
  }
  nr = 0;
  for (i = 0; i < n; i = i + 3)
    if (s[i] != 'B') nr++;
  for (i = 1; i < n; i = i + 3)
    if (s[i] != 'G') nr++;
  for (i = 2; i < n; i = i + 3)
    if (s[i] != 'R') nr++;
  if (nr < nrmin) {
    nrmin = nr;
    ok = 6;
  }
  cout << nrmin << '\n';
  if (ok == 1) {
    while (n != 0) {
      cout << 'R';
      n--;
      if (n == 0) break;
      cout << 'G';
      n--;
      if (n == 0) break;
      cout << 'B';
      n--;
    }
  }
  if (ok == 2) {
    while (n != 0) {
      cout << 'R';
      n--;
      if (n == 0) break;
      cout << 'B';
      n--;
      if (n == 0) break;
      cout << 'G';
      n--;
    }
  }
  if (ok == 3) {
    while (n != 0) {
      cout << 'G';
      n--;
      if (n == 0) break;
      cout << 'R';
      n--;
      if (n == 0) break;
      cout << 'B';
      n--;
    }
  }
  if (ok == 4) {
    while (n != 0) {
      cout << 'G';
      n--;
      if (n == 0) break;
      cout << 'B';
      n--;
      if (n == 0) break;
      cout << 'R';
      n--;
    }
  }
  if (ok == 5) {
    while (n != 0) {
      cout << 'B';
      n--;
      if (n == 0) break;
      cout << 'R';
      n--;
      if (n == 0) break;
      cout << 'G';
      n--;
    }
  }
  if (ok == 6) {
    while (n != 0) {
      cout << 'B';
      n--;
      if (n == 0) break;
      cout << 'G';
      n--;
      if (n == 0) break;
      cout << 'R';
      n--;
    }
  }
}
