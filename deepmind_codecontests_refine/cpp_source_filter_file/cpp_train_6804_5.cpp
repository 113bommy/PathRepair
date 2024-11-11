#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
long long n, k, most, res = 1, a[N], sum[N];
map<long long, long long> cnt;
void Special_Case() {
  for (int i = 1; i <= n; i++) {
    long long curr = a[i] + 1000000000;
    cnt[curr]++;
    if (cnt[curr] > res) {
      res = cnt[curr];
      most = curr - 1000000000;
    }
  }
  cout << res << " " << most << '\n';
}
void Input() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (k == 0) {
    Special_Case();
    exit(0);
  }
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
}
int Binary_Search(int i) {
  long long curr_res = 0, l = 1, r = i - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (abs(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1])) < k) {
      curr_res = i - mid;
      r = mid - 1;
    } else if (abs(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1])) == k) {
      curr_res = i - mid;
      break;
    } else
      l = mid + 1;
  }
  return curr_res;
}
void Solve() {
  for (int i = 1; i <= n; i++) {
    long long curr = Binary_Search(i) + 1;
    if (curr > res) {
      res = curr;
      most = a[i];
    }
  }
  cout << res << " " << most << '\n';
}
int main() {
  Input();
  Solve();
  return 0;
}
