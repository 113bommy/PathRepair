#include <bits/stdc++.h>
using namespace std;
int a[25], b[25];
int c[10], cnt[10];
int ans;
bool flag;
bool dfs(int pos, bool l, bool r) {
  if (flag) return true;
  if (!pos) return true;
  if (!l && !r) return true;
  if (l && r) {
    if (a[pos] == b[pos]) {
      if (!c[a[pos]]) return false;
      c[a[pos]]--;
      if (dfs(pos - 1, l, r)) return flag = true;
      c[a[pos]]++;
    } else {
      for (int i = a[pos] + 1; i < b[pos]; i++)
        if (c[i]) return flag = true;
      if (c[a[pos]]) {
        c[a[pos]]--;
        if (dfs(pos - 1, l, false)) return flag = true;
        c[a[pos]]++;
      }
      if (c[b[pos]]) {
        c[b[pos]]--;
        if (dfs(pos - 1, false, r)) return flag = true;
        c[a[pos]]++;
      }
    }
  } else if (l) {
    for (int i = a[pos] + 1; i < 10; i++)
      if (c[i]) return flag = true;
    if (c[a[pos]]) {
      c[a[pos]]--;
      if (dfs(pos - 1, l, r)) return flag = true;
      c[a[pos]]++;
    }
  } else {
    for (int i = 0; i < b[pos]; i++) {
      if (c[i]) return flag = true;
    }
    if (c[b[pos]]) {
      c[b[pos]]--;
      if (dfs(pos - 1, l, r)) return flag = true;
      c[b[pos]]++;
    }
  }
  return false;
}
bool check() {
  memcpy(c, cnt, sizeof(cnt));
  flag = false;
  dfs(18, 1, 1);
  return flag;
}
void dfs(int digit, int n) {
  if (digit == 9 || !n) {
    cnt[digit] = n;
    if (check()) ans++;
    return;
  }
  for (int i = 0; i <= n; i++) {
    cnt[digit] = i;
    dfs(digit + 1, n - i);
    cnt[digit] = 0;
  }
}
bool single_check(long long l) {
  for (unsigned long long i = 1; i <= 1000000000000000000LL; i *= 10)
    if (i >= l) return true;
  return false;
}
int main() {
  long long l, r;
  cin >> l >> r;
  if (r == 1000000000000000000LL) {
    if (l == r) {
      printf("1\n");
      return 0;
    }
    r--;
    ans += single_check(l);
  }
  for (int i = 1; i <= 18; i++, l /= 10, r /= 10) {
    a[i] = l % 10;
    b[i] = r % 10;
  }
  dfs(0, 18);
  cout << ans << endl;
  return 0;
}
