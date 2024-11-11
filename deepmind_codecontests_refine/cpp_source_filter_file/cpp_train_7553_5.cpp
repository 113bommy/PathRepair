#include <bits/stdc++.h>
using namespace std;
void ASS(bool b) {
  if (!b) {
    ++*(int*)0;
  }
}
#pragma comment(linker, "/STACK:106777216")
const int N = 1 << 17;
struct S {
  string s;
  int x;
};
bool operator<(const S& a, const S& b) { return a.s < b.s; }
S a[N];
int b[N];
int FF(int* b, int* c, int n) {
  int p = 0;
  int res = 0;
  for (int i = 0; i < (int)(n); i++) {
    while (p < n && c[p] < b[i]) p++;
    if (p < n) {
      p++;
      res++;
    }
  }
  return res;
}
int Best(int n, int ind) {
  int v = a[ind].x + b[n - 1];
  static int c[N];
  int p = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (i < ind) c[p++] = v - a[i].x - 1;
    if (i > ind) c[p++] = v - a[i].x;
  }
  sort(c, c + p);
  return n - 1 - FF(b, c, n - 1);
}
int Worst(int n, int ind) {
  int v = a[ind].x + b[0];
  static int c[N];
  int p = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (i < ind) c[p++] = v - a[i].x;
    if (i > ind) c[p++] = v - a[i].x + 1;
  }
  sort(c, c + p);
  return FF(c, b, n - 1);
}
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> a[i].s >> a[i].x;
  cin >> m;
  for (int i = 0; i < (int)(m); i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  string vasya;
  cin >> vasya;
  int ind = 0;
  while (ind < n && a[ind].s != vasya) ind++;
  ASS(ind < n);
  int res0 = Best(n, ind) + 1;
  int res1 = Worst(n, ind) + 1;
  cout << res0 << " " << res1 << endl;
  return 0;
}
