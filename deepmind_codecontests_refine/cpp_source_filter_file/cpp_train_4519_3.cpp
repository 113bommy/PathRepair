#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
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
  if (n == 1) return base % mo;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
int N, K;
vector<int> E[3000];
long double ans;
int main() {
  scanf("%d%d", &N, &K);
  for (int i = (1); i <= (N); ++i)
    for (int j = (i + 1); j <= (N); ++j) {
      int x;
      scanf("%d", &x);
      if (x != -1) E[i].push_back(x), E[j].push_back(x);
    }
  for (int i = (1); i <= (N); ++i)
    if (E[i].size() >= K) {
      long double tmp = 1;
      for (int j = (0); j <= (K - 2); ++j) {
        tmp *= (E[i].size() - 1 - j);
        tmp /= N - j;
      }
      tmp *= K;
      tmp /= N - (K - 1);
      for (int j = (0); j < (E[i].size()); ++j) ans += tmp * E[i][j];
    }
  printf("%lld\n", (long long)(ans + 1e-2));
  return 0;
}
