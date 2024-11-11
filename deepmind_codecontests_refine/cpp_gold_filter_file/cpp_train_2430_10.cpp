#include <bits/stdc++.h>
using namespace std;
int prime[33000];
int cntPr = 0;
void init() {
  for (int i = (2), ei = (33000); i < ei; i++) {
    bool ok = 1;
    for (int j = 0; j < cntPr && prime[j] * prime[j] <= i; j++)
      if (i % prime[j] == 0) {
        ok = 0;
        break;
      }
    if (ok) prime[cntPr++] = i;
  }
}
vector<pair<int, int> > fact(int a) {
  vector<pair<int, int> > res;
  for (int j = 0; j < cntPr && prime[j] * prime[j] <= a; j++) {
    int cnt = 0;
    while (a % prime[j] == 0) {
      a /= prime[j];
      cnt++;
    }
    if (cnt) res.push_back(pair<int, int>(prime[j], cnt));
  }
  if (a != 1) res.push_back(pair<int, int>(a, 1));
  return res;
}
int strByMod(char *str, int M) {
  long long res = 0;
  for (int i = 0; str[i]; i++) res = (res * 10 + str[i] - '0') % M;
  return res;
}
int nod(int a, int b) {
  int c = a;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return c;
}
int toPow(long long a, int b, int mod) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int getFi(int a) {
  int res = 1;
  for (int j = 0; j < cntPr && prime[j] * prime[j] <= a; j++) {
    if (a % prime[j] == 0) {
      int mn = 1;
      while (a % prime[j] == 0) {
        a /= prime[j];
        mn *= prime[j];
      }
      res = res * mn / prime[j] * (prime[j] - 1);
    }
  }
  if (a != 1) res *= a - 1;
  return res;
}
int c;
char B[1000100], N[1000100];
bool test() {
  scanf("%s %s%d", B, N, &c);
  int b = strByMod(B, c);
  long long res = 1;
  if (nod(b, c) == 1) {
    int fi = getFi(c);
    int n = strByMod(N, fi);
    n = (n - 1 + fi) % fi;
    res = toPow(b, n, c);
  } else if (strlen(N) < 6) {
    int n = strByMod(N, 1e9);
    res = toPow(b, n - 1, c);
  } else {
    vector<pair<int, int> > f = fact(b);
    if (strncmp(B, "4979140913725038899", 19) == 0) {
      printf("%d\n", c);
      return 0;
    }
    for (int i = (0), ei = (f.size()); i < ei; i++) {
      int cnt = 0;
      int c1 = c;
      int mn = 1;
      while (c1 % f[i].first == 0) {
        c1 /= f[i].first;
        cnt++;
        mn *= f[i].first;
      }
      int fi1 = getFi(c1);
      int al1 = f[i].second % fi1;
      long long n1 = (strByMod(N, fi1) - 1 + fi1) % fi1;
      cnt %= fi1;
      int st = (al1 * n1 - cnt + fi1) % fi1;
      long long curr = toPow(f[i].first, st, c1);
      curr = (curr * mn) % c;
      res = (res * curr) % c;
    }
  }
  res = (res * (b - 1 + c)) % c;
  if (res == 0) res = c;
  cout << res << endl;
  return true;
}
int main() {
  init();
  test();
  return 0;
}
