#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
pair<long long, int> a[100010], b[100010];
long long acum_a[100010], acum_b[100010];
long long print[100010];
int less_to(long long value, int n) {
  int low = 1, high = n, ans = 0;
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (a[mid].first < value) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long maxim_level, cfM, cfm, units;
  cin >> n >> maxim_level >> cfM >> cfm >> units;
  long long mini = inf, maximums = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    mini = min(mini, a[i].first);
    if (a[i].first == maxim_level) maximums++;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    b[i] = a[n - i + 1];
  }
  for (int i = 1; i <= n; i++) {
    acum_a[i] = acum_a[i - 1] + a[i].first;
    acum_b[i] = acum_b[i - 1] + b[i].first;
  }
  long long ans = maximums * cfM + mini * cfm;
  int start_i = maximums;
  for (long long i = start_i; i <= n; i++) {
    long long sum_first_i = acum_b[i];
    long long i_need = i * maxim_level;
    long long diff = i_need - sum_first_i;
    if (units < diff) break;
    if (i == n) {
      maximums = n;
      mini = maxim_level;
      ans = n * cfM + mini * cfm;
      break;
    }
    long long res = units - diff;
    long long others = n - i;
    long long low = a[1].first, high = maxim_level;
    long long minimum_binary = a[1].first;
    while (low <= high) {
      long long mid = (low + high) >> 1LL;
      int x = less_to(mid, others);
      long long sum_first_x = acum_a[x];
      long long i_need_binary = x * mid;
      long long diff_binary = i_need_binary - sum_first_x;
      if (res < diff_binary) {
        high = mid - 1;
      } else {
        minimum_binary = mid;
        low = mid + 1;
      }
    }
    long long ans_temp = i * cfM + minimum_binary * cfm;
    if (ans < ans_temp) {
      maximums = i;
      mini = minimum_binary;
      ans = ans_temp;
    }
  }
  for (int i = 1; i <= maximums; i++) {
    b[i].first = maxim_level;
  }
  for (int i = 1; i <= n; i++) {
    print[b[i].second] = b[i].first;
    if (print[b[i].second] < mini) print[b[i].second] = mini;
  }
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) {
    cout << print[i] << " ";
  }
  cout << "\n";
}
