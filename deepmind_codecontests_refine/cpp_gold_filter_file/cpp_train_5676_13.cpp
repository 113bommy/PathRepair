#include <bits/stdc++.h>
const int ms = 100100;
int n;
long long tot, cmax, cmin, m;
std::pair<long long, long long> b[ms];
long long a[ms], ans[ms], sum[ms];
void read() {
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = std::pair<long long, long long>(a[i], i);
  }
  std::sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i].first;
  sum[n + 1] = sum[n];
  b[n + 1].first = b[n].first;
}
long long can_until(int l, int r, long long cur_m) {
  int orr = r, orl = l;
  long long orm = cur_m;
  while (l != r) {
    int mid = (l + r + 1) / 2;
    if (b[mid].first * mid - sum[mid] <= cur_m)
      l = mid;
    else
      r = mid - 1;
  }
  cur_m -= b[l].first * r - sum[l];
  long long ans = std::min(b[r].first + cur_m / r, tot);
  if (r < orr) ans = std::min(ans, b[r + 1].first);
  return ans;
}
long long solve(int on) {
  long long cur_m = m - (tot * (n - on) - (sum[n] - sum[on]));
  long long ans;
  if (cur_m < 0)
    ans = -1;
  else
    ans = (n - on) * cmax + can_until(0, on, cur_m) * cmin;
  return ans;
}
void get_solution(int on) {
  for (int i = on + 1; i <= n; i++) b[i].first = tot;
  long long cur_m = m - (tot * (n - on) - (sum[n] - sum[on]));
  long long lower = can_until(0, on, cur_m);
  for (int i = 1; i <= n; i++) {
    b[i].first = std::max(b[i].first, lower);
    std::swap(b[i].first, b[i].second);
  }
  std::sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    if (i != 1) std::cout << ' ';
    std::cout << b[i].second;
  }
  std::cout << '\n';
}
int main() {
  while (std::cin >> n >> tot >> cmax >> cmin >> m) {
    read();
    if (tot * n - sum[n] <= m) {
      std::cout << n * cmax + tot * cmin << '\n';
      for (int i = 0; i < n; i++) {
        if (i) std::cout << ' ';
        std::cout << tot;
      }
      std::cout << '\n';
      continue;
    }
    long long ans = -1;
    int on = -1;
    for (int i = 1; i <= n; i++) {
      long long cur_ans = solve(i);
      if (cur_ans >= ans) {
        ans = cur_ans;
        on = i;
      }
    }
    std::cout << ans << '\n';
    get_solution(on);
  }
}
