#include <bits/stdc++.h>
using namespace std;
const int base = 1e9;
const int maxn = 10005;
const int logn = 20;
const int inf = 1e5;
const int alpha = 26;
const int my_hash = 29;
const int my_mod = 2495828519;
const long long l_inf = 4e18;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, ans_1 = inf, ans_2, ans_3;
vector<int> a;
int get(int s, int dif) {
  int k = 0;
  for (int j = 0; j < n; j++) k = max(k, abs(a[j] - (a[0] + s + dif * j)));
  return k;
}
int main() {
  scanf("%d", &n);
  a = vector<int>(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  for (int i = 0; i <= maxn; i++) {
    int l = 0, r = 2 * maxn;
    while (l != r) {
      int mid = (l + r) / 2;
      get(mid - maxn, i) < get(mid + 1 - maxn, i) ? r = mid : l = mid + 1;
    }
    int k = get(l - maxn, i);
    if (k < ans_1) {
      ans_1 = k;
      ans_2 = a[0] + l - maxn;
      ans_3 = i;
    }
  }
  printf("%d\n%d %d", ans_1, ans_2, ans_3);
}
