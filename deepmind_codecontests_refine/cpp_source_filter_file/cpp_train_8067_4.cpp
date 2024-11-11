#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1677721600")
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double ee = exp(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const double pi = acos(-1.0);
const long long iinf = 0x3f3f3f3f3f3f3f3f;
int readT() {
  char c;
  int ret = 0, flg = 0;
  while (c = getchar(), (c < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    flg = 1;
  else
    ret = c ^ 48;
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
  return flg ? -ret : ret;
}
long long readTL() {
  char c;
  int flg = 0;
  long long ret = 0;
  while (c = getchar(), (c < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    flg = 1;
  else
    ret = c ^ 48;
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
  return flg ? -ret : ret;
}
int cnt[301];
int a[101];
int tmp[30001];
int len;
int binarySearch(int key) {
  if (len == 0 || tmp[len] <= key)
    tmp[++len] = key;
  else {
    int lo = lower_bound(tmp, tmp + len, key) - tmp;
    tmp[lo] = key;
  }
  return len;
}
int main() {
  int n = readT();
  int t = readT();
  memset(cnt, 0, sizeof(cnt));
  int maxCnt = 0;
  for (int i = (0); i <= (n - 1); i++) {
    a[i] = readT();
    cnt[a[i]]++;
    maxCnt = ((maxCnt) > (cnt[a[i]]) ? (maxCnt) : (cnt[a[i]]));
  }
  int m = ((t) < (300) ? (t) : (300));
  len = 0;
  for (int i = (0); i <= (m * n - 1); i++) {
    binarySearch(a[i % n]);
  }
  len += (t - m) * maxCnt;
  cout << len << endl;
  return 0;
}
