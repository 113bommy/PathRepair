#include <bits/stdc++.h>
using namespace std;
int n, D;
int a[(int)(2e5 + 10)], Hash[(int)(2e5 + 10)];
int sum[(int)(2e5 + 10)];
int res = 0;
int cnt[(int)(2e5 + 10)];
void solve1(int x) {
  unordered_map<int, int> mn;
  mn[0] = 0;
  memset(sum, 0, (n + 5) * sizeof(int));
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (a[i] == x)
      sum[i]--;
    else if (a[i] == D)
      sum[i]++;
    if (mn.count(sum[i]) == 0) mn[sum[i]] = i;
    res = max(res, i - mn[sum[i]]);
  }
}
void solve2(int x) {
  memset(cnt, 0, (n + 5) * sizeof(int));
  int l = 1, eq = 0;
  cnt[a[l]]++;
  if (cnt[a[l]] == x) eq++;
  for (int i = 2; i <= n; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == x)
      eq++;
    else if (cnt[a[i]] > x) {
      if (cnt[a[i]] == x + 1) eq--;
      while (cnt[a[i]] > x) {
        cnt[a[l]]--;
        if (cnt[a[l]] == x)
          eq++;
        else if (cnt[a[l]] == x - 1)
          eq--;
        l++;
      }
    }
    if (eq >= 2) res = max(res, i - l + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], Hash[a[i]]++;
  int maxx = 0;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (Hash[i] > maxx) {
      maxx = Hash[i];
      D = maxx;
      count = 1;
    } else if (Hash[i] == maxx) {
      count++;
    }
  }
  if (count >= 2)
    cout << n << endl;
  else {
    int lim = sqrt(n);
    for (int i = 1; i <= n; i++)
      if (Hash[i] >= lim && i != D) solve1(i);
    for (int i = 1; i < lim; i++) solve2(i);
    cout << res << endl;
  }
}
