#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) { return (ull)rng() % B; }
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int main() {
  startTime = clock();
  int n, k;
  scanf("%d%d", &n, &k);
  int pw = 1;
  int ans = 0;
  while (pw < n) {
    pw *= k;
    ans++;
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int x = i, y = j, z = 1;
      while (x % k >= y % k) {
        x /= k;
        y /= k;
        z++;
      }
      printf("%d ", z);
    }
  printf("\n");
  return 0;
}
