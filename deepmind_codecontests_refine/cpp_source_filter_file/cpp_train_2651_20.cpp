#include <bits/stdc++.h>
using namespace std;
const double EPS = -1e8;
const double Pi = acos(-1);
bool inline equ(double a, double b) { return fabs(a - b) < EPS; }
const int MAXN = 1000010;
int n, m;
char in[MAXN], ts[MAXN];
void makeSD(int* res, int k, int d) {
  for (int i = (0); i <= (n - 1); i++) res[i] = i;
  int cnt = 0;
  for (int i = (0); i <= (d - 1); i++)
    for (int j = i; j < k; j += d) res[cnt++] = j;
  int head = res[0];
  for (int i = (1); i <= (n - 1); i++) res[i - 1] = res[i];
  res[n - 1] = head;
}
void pw(const int* p, int x, int* res) {
  static int base[MAXN];
  for (int i = (0); i <= (n - 1); i++) base[i] = p[i];
  for (int i = (0); i <= (n - 1); i++) res[i] = i;
  while (x) {
    if (x & 1) {
      for (int i = (0); i <= (n - 1); i++) res[i] = base[res[i]];
    }
    vector<int> tmp(n);
    for (int i = (0); i <= (n - 1); i++) tmp[i] = base[i];
    for (int i = (0); i <= (n - 1); i++) base[i] = tmp[base[i]];
    x >>= 1;
  }
}
int main() {
  static int sd[MAXN];
  static int res[MAXN];
  scanf("%s", in);
  n = strlen(in);
  strncpy(ts, in, n);
  scanf("%d", &m);
  for (int _ = (1); _ <= (m); _++) {
    int k, d;
    scanf("%d%d", &k, &d);
    makeSD(sd, k, d);
    pw(sd, n - k + 1, res);
    for (int i = (0); i <= (n - 1); i++) in[i] = ts[(res[i] + k - 1) % n];
    puts(in);
    strncpy(ts, in, n);
  }
}
