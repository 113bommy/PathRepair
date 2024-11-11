#include <bits/stdc++.h>
const int MAXN = 1e5 + 10;
int n;
int a[MAXN];
int cnt[MAXN];
long long solve1() {
  int mid = (n + 1) >> 1;
  static int tmp[MAXN];
  memset(tmp, 0, sizeof tmp);
  for (int i = mid + 1; i <= n; i++) {
    tmp[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (tmp[i] != cnt[i] / 2) return 0;
  }
  int p = (n & 1) ? (mid - 1) : mid;
  int l = 1, r = p;
  while (a[l] == a[n - l + 1] && l <= r) l++;
  if (l >= r) return (long long)p * (p + 1) / 2;
  while (a[r] == a[n - r + 1]) r--;
  return (long long)l * (p - r + 1);
}
long long solve2() {
  int mid = (n + 1) >> 1;
  int p = (n & 1) ? (mid - 1) : mid;
  static int tmp[MAXN];
  memset(tmp, 0, sizeof tmp);
  int rr = n;
  while (1) {
    if (rr == mid + 1 || ++tmp[a[rr]] > cnt[a[rr]] / 2) break;
    rr--;
  }
  long long ans = 0;
  for (int i = 1; i <= p; i++) {
    int opp = n - i + 1;
    ans += std::max(opp - rr, 0);
    if (a[i] != a[opp]) break;
  }
  return ans;
}
long long solve3() {
  int mid = (n + 1) >> 1;
  long long ans = 0;
  static int tmp[MAXN];
  memset(tmp, 0, sizeof tmp);
  for (int i = mid + 1; i <= n; i++) {
    tmp[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (tmp[i] != cnt[i] / 2) return 0;
  }
  for (int i = 1; i < mid; i++) {
    int opp = n - i + 1;
    ans++;
    if (a[i] != a[opp]) break;
  }
  return ans;
}
long long solve4() {
  long long ans = 0;
  int p = (n & 1) ? (((n + 1) >> 1) - 1) : ((n + 1) >> 1);
  for (int i = 1; i <= p; i++) {
    int opp = n - i + 1;
    ans++;
    if (a[i] != a[opp]) break;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  std::vector<int> odd;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] & 1) odd.push_back(i);
  }
  if (odd.size() >= 2) {
    puts("0");
    return 0;
  } else if (odd.size() == 1) {
    int mid = (1 + n) >> 1;
    int val = odd[0];
    long long ans = 0;
    if (a[mid] == val) {
      ans += solve1();
      std::reverse(a + 1, a + n + 1);
      ans += solve1();
      std::reverse(a + 1, a + n + 1);
    }
    ans += solve4();
    bool flag = 1;
    for (int i = 1; i <= mid; i++) {
      if (a[i] != a[n - i + 1]) flag = 0;
    }
    ans += flag;
    ans += solve2();
    ans += solve3();
    std::reverse(a + 1, a + n + 1);
    ans += solve2();
    ans += solve3();
    printf("%lld\n", ans);
  } else {
    long long ans = 0;
    ans += solve1();
    std::reverse(a + 1, a + n + 1);
    ans += solve1();
    std::reverse(a + 1, a + n + 1);
    ans += solve4();
    ans += solve2();
    std::reverse(a + 1, a + n + 1);
    ans += solve2();
    printf("%lld\n", ans);
  }
}
