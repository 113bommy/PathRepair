#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const double eps = 1e-7;
const double PI = cos(-1.0);
map<int, int> used, has;
int ans[maxn], num[maxn];
bool mycmp(int a, int b) { return a > b; }
int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    used.clear();
    has.clear();
    for (int i = 0; i < n * n; ++i) {
      scanf("%d", num + i);
      has[num[i]]++;
    }
    sort(num, num + n * n, mycmp);
    int amount = 0;
    for (int i = 0; i < n * n; ++i) {
      if (used[num[i]] < has[num[i]]) {
        ans[amount++] = num[i];
        used[num[i]]++;
        for (int j = 0; j < amount; ++j) {
          used[gcd(num[i], ans[j])]++;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
