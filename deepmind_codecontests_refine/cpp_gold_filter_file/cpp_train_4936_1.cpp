#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 100000 + 5;
const int MAX = 10000000 + 5;
int a[N];
int t[MAX] = {0};
int get_sum(int r) {
  int res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) res += t[r];
  return res;
}
int get_sum(int l, int r) {
  if (l == 0) return get_sum(r);
  return get_sum(r) - get_sum(l - 1);
}
void add(int i, int val) {
  for (; i < MAX; i = i | (i + 1)) t[i] += val;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    add(a[i], 1);
  }
  int m = *min_element(a, a + n);
  int M = *max_element(a, a + n);
  if (m <= k + 1) {
    cout << m << endl;
    return 0;
  }
  int ans = -1;
  for (int g = k + 1; g <= m; g++) {
    int tmax = M / g;
    int total_count = 0;
    for (int t = 0; t <= tmax; t++) {
      total_count += get_sum(t * g, t * g + k);
    }
    if (total_count != n) continue;
    ans = g;
  }
  cout << ans;
  return 0;
}
