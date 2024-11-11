#include <bits/stdc++.h>
double eps = 1e-9;
using namespace std;
int n, a[100005], m, b[100005], cnt[100005];
bool check(int x) {
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= m; i++) {
    long long val1 = (long long)b[i] - (long long)x;
    long long val2 = (long long)b[i] + (long long)x;
    int idx_left = 0, idx_right = n + 1;
    int l = 1, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if ((long long)a[mid] < val1)
        l = mid;
      else
        r = mid - 1;
    }
    if (l > r) swap(l, r);
    if ((long long)a[l] < val1)
      idx_left = l;
    else if ((long long)a[r] < val1)
      idx_left = r;
    l = 1, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if ((long long)a[mid] > val2)
        r = mid;
      else
        l = mid + 1;
    }
    if (l > r) swap(l, r);
    if ((long long)a[l] > val2)
      idx_right = l;
    else if ((long long)a[r] > val2)
      idx_right = r;
    idx_left++;
    cnt[idx_left]++, cnt[idx_right]--;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += cnt[i];
    if (!sum) return 0;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int l = 0, r = 2000000000;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l > r) swap(l, r);
  if (check(l))
    cout << l << endl;
  else
    cout << r << endl;
}
