#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int f = 1, sum = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
long long readd() {
  char c = getchar();
  long long f = 1, sum = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
int q;
int n;
long long m;
long long siz[100005];
int s = 34 + 32 + 2;
string str =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string fr, mid, bac;
int frsiz, midsiz, bacsiz;
void init() {
  siz[0] = 75;
  for (int i = 1; i <= 100000; i++) {
    siz[i] = siz[i - 1] * 2 + s;
    if (siz[i] > 2e18) siz[i] = 2e18;
  }
  fr = "What are you doing while sending \"";
  mid = "\"? Are you busy? Will you send \"";
  bac = "\"?";
  frsiz = fr.size();
  midsiz = mid.size();
  bacsiz = bac.size();
}
char dfs(int n, long long m) {
  if (n == 0) return str[m - 1];
  if (m <= frsiz) return fr[m - 1];
  if (m <= frsiz + siz[n - 1]) return dfs(n - 1, m - frsiz);
  if (m <= frsiz + midsiz + siz[n - 1]) return mid[m - frsiz - siz[n - 1] - 1];
  if (m <= frsiz + midsiz + siz[n - 1] * 2)
    return dfs(n - 1, m - frsiz - midsiz - siz[n - 1]);
  return bac[m - frsiz - midsiz - siz[n - 1] * 2 - 1];
}
int main() {
  init();
  q = read();
  while (q--) {
    n = read();
    m = readd();
    if (siz[n] < m)
      cout << '.';
    else
      cout << dfs(n, m);
  }
  return 0;
}
