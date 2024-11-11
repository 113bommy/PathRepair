#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
;
const double pi = acos(-1.0);
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
const int mo = 1000000007;
long long l[10], cur[10];
char s[200000];
string q[200000];
int m;
long long ans;
int main() {
  scanf("%s", s + 1);
  scanf("%d", &m);
  for (int i = (1); i <= (m); ++i) cin >> q[i];
  for (int i = (0); i <= (9); ++i) l[i] = 1, cur[i] = i;
  for (int i = (m); i >= (1); --i) {
    long long tmp = 0;
    long long curl = 0;
    for (int j = (3); j < (q[i].size()); ++j) {
      tmp = (tmp * Pow(10, l[q[i][j] - '0'], mo) + cur[q[i][j] - '0']) % mo;
      curl += l[q[i][j] - '0'];
      curl %= mo;
    }
    l[q[i][0] - '0'] = curl;
    cur[q[i][0] - '0'] = tmp;
  }
  int len = strlen(s + 1);
  for (int i = (1); i <= (len); ++i)
    ans = ans * Pow(10, l[s[i] - '0'], mo) + cur[s[i] - '0'], ans %= mo;
  printf("%lld\n", ans);
  return 0;
}
