#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &first) {
  int f = 1;
  first = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    first = (first << 3) + (first << 1) + c - '0';
    c = getchar();
  }
  first *= f;
  return;
}
void write(register int first) {
  if (first < 0) {
    first = ~first + 1;
    putchar('-');
  }
  if (first > 9) write(first / 10);
  putchar(first % 10 + '0');
  return;
}
int n, pm[(int)(1e6 + 1)], tot;
bool pr[(int)(1e6 + 1)];
map<long long, bool> bk;
vector<long long> f;
long long ans, a[(int)(2e5 + 1)];
void sieve() {
  for (register int(i) = (2); (i) <= ((int)(1e6 + 1) - 1); i++) {
    if (!pr[i]) pm[++tot] = i;
    for (int j = 1; j <= tot && pm[j] * i < (int)(1e6 + 1); j++) {
      pr[pm[j] * i] = 1;
      if (!(i % pm[j])) break;
    }
  }
  return;
}
void solve(long long first) {
  for (int i = 1; i <= tot && pm[i] <= first; i++) {
    if (!(first % pm[i])) {
      if (!bk[pm[i]]) {
        bk[pm[i]] = 1;
        f.push_back(pm[i]);
      }
      while (!(first % pm[i])) first /= pm[i];
    }
  }
  if (first > 1)
    if (!bk[first]) {
      bk[first] = 1;
      f.push_back(first);
    }
  return;
}
long long calc(long long first) {
  long long ret = 0;
  for (register int(i) = (1); (i) <= (n); i++)
    ret +=
        a[i] < first ? first - a[i] : min(a[i] % first, first - a[i] % first);
  return ret;
}
int main() {
  srand(time(0));
  sieve();
  read(n);
  for (register int(i) = (1); (i) <= (n); i++) read(a[i]);
  random_shuffle(a + 1, a + 1 + n);
  for (register int(i) = (1); (i) <= (100); i++) {
    solve(a[i]);
    solve(a[i] + 1);
    solve(a[i] - 1);
  }
  ans = n;
  for (auto p : f) ans = min(ans, calc(p));
  write(ans);
  return 0;
}
