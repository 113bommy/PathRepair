#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  int flag = 1;
  for (c = getchar(); !(c >= '0' && c <= '9' || c == '-'); c = getchar())
    ;
  if (c == '-')
    flag = -1, n = 0;
  else
    n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
  n *= flag;
}
int main(int argc, char *argv[]) {
  int n, a[2000], t, T, ans = inf;
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  for (int t = (0); t <= (200); ++t) {
    int cost = 0;
    for (int i = (1); i <= (n); ++i) {
      if (a[i] < t)
        cost += t - 1 - a[i];
      else if (a[i] > t)
        cost += a[i] - (t + 1);
    }
    if (cost < ans) {
      ans = cost;
      T = t;
    }
  }
  cout << T << ' ' << ans << endl;
  return 0;
}
