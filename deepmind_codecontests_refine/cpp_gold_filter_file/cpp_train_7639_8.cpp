#include <bits/stdc++.h>
using namespace std;
const int maxN = 100100;
const int maxK = 1010;
int b, d, n, m;
string s, t, v;
int f[200], g[200], f1[200];
long long ht;
void init() {
  scanf("%i %i\n", &b, &d);
  getline(cin, s);
  n = s.length();
  getline(cin, v);
  m = v.length();
  t = s;
  for (int i = 0; i < m + 2; i++) t = t + s;
  for (int start = 0; start < n; start++) {
    int ht = 0;
    f[start] = 1000000000;
    for (int i = start; i < t.length(); i++) {
      if (v[ht] == t[i]) ++ht;
      if (ht == m) {
        f[start] = i - start;
        g[start] = 1;
        break;
      }
    }
  }
}
bool xuly() {
  long long ht = 0;
  long long sl = 0;
  for (int i = 0; i < n; i++) f1[i] = f[i];
  for (int start = 0; start < n; start++)
    if (f1[start] < n - 1) {
      ht = start;
      g[start] = 0;
      while (ht - start + f[ht % n] < n) {
        ++g[start];
        ht += f[ht % n] + 1;
      }
      f1[start] = (ht - 1 - start);
    }
  ht = 0;
  while (ht + f1[ht % n] < n * b) {
    sl += g[ht % n];
    ht += f1[ht % n] + 1;
  }
  while (ht + f[ht % n] < n * b) {
    sl += 1;
    ht += f[ht % n] + 1;
  }
  cout << sl / d;
  return true;
}
int main() {
  init();
  if (!xuly()) cout << 0;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
