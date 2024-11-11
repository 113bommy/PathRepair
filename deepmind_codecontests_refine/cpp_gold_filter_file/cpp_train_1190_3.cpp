#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0;
  bool ok = 0;
  char c = getchar();
  while (c < 48 || c > 57) ok |= (c == '-'), c = getchar();
  while (c > 47 && c < 58) x *= 10, x += c - 48, c = getchar();
  if (ok) x = -x;
  return x;
}
void print(int x, int y = 0) {
  printf("%d", x);
  if (y == 0)
    puts("");
  else
    putchar(' ');
}
void printll(long long x, int y = 0) {
  printf("%I64d", x);
  if (y == 0)
    puts("");
  else
    putchar(' ');
}
string read_s() {
  string s = "";
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  while (isalpha(c)) s += c, c = getchar();
  return s;
}
char read_c() {
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  return c;
}
void prints(string x) {
  char s[100002];
  for (int i = 0; i < x.size(); i++) s[i] = x[i];
  s[x.size()] = '\0';
  puts(s);
}
const long long INF = 1e17;
long long X[100002], Y[100002];
bool comp(int l, int r) { return (Y[l] < Y[r]); }
long long dist(long long x, long long y) {
  return (X[x] - X[y]) * (X[x] - X[y]) + (Y[x] - Y[y]) * (Y[x] - Y[y]);
}
long long f(int l, int r) {
  if (l >= r) return INF;
  int mid = (l + r) >> 1;
  long long mi = min(f(l, mid), f(mid + 1, r));
  long long line = (X[mid] + X[mid + 1]) / 2;
  long long c = (long long)sqrt(mi);
  vector<int> LL, RR;
  for (int i = l; i <= r; i++) {
    if (i <= mid) {
      if (line + 1 - X[i] <= c) LL.push_back(i);
    } else {
      if (X[i] - line <= c) RR.push_back(i);
    }
  }
  sort(LL.begin(), LL.end(), comp);
  sort(RR.begin(), RR.end(), comp);
  int L = 0, R = 0;
  for (int i = 0; i < LL.size(); i++) {
    while (R + 1 < RR.size() && Y[RR[R + 1]] - Y[LL[i]] <= c) R++;
    while (L < RR.size() && Y[LL[i]] - Y[RR[L]] > c) L++;
    for (int j = L; j <= R; j++) mi = min(mi, dist(LL[i], RR[j]));
  }
  return mi;
}
pair<long long, long long> w[100002];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    w[i].second = read() + w[i - 1].second;
    w[i].first = i;
  }
  sort(w + 1, w + 1 + n);
  for (int i = 1; i <= n; i++) {
    X[i] = w[i].first;
    Y[i] = w[i].second;
  }
  printll(f(1, n));
}
