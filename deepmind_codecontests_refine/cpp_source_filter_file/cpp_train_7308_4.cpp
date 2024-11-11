#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000 + 5];
int p[200000 + 5];
int f_1[200000 + 5];
long long f_2[200000 + 5];
void add_1(int x, int a) {
  for (int i = x; i <= n; i += (i & (-i))) {
    f_1[i] += a;
  }
}
void add_2(int x, int a) {
  for (int i = x; i <= n; i += (i & (-i))) {
    f_2[i] += a;
  }
}
int query_1(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= (i & (-i))) {
    ans += f_1[i];
  }
  return ans;
}
int query_2(int x) {
  long long ans = 0;
  for (int i = x; i > 0; i -= (i & (-i))) {
    ans += f_2[i];
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }
  long long ans = 0, tmp = 0, sum = 0;
  int now;
  for (int i = 1; i <= n; i++) {
    ans += (i - 1) - query_1(p[i]);
    add_1(p[i], 1);
    add_2(p[i], p[i]);
    tmp += p[i];
    int left = 1, right = n, mid;
    while (left < right) {
      mid = (left + right + 1) >> 1;
      now = query_1(mid);
      if (now * 2 > i) {
        right = mid - 1;
      } else {
        left = mid;
      }
    }
    now = query_1(left);
    long long now_2 = query_2(left);
    long long now_3 = tmp - now_2;
    sum = 1ll * left * now - now_2 - 1ll * now * (now - 1) / 2 + now_3 -
          1ll * left * (i - now) - 1ll * (i - now + 1) * (i - now) / 2;
    cout << ans + sum << ' ';
  }
  puts("");
  return 0;
}
