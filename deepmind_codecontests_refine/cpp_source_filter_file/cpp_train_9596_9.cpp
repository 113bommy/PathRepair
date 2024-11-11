#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
const long long inf = 1e18 + 10;
long long mod = 998244353;
long long sui[maxn];
int n, m, num[maxn];
struct node {
  int x, y, id;
} a[maxn], b[maxn];
bool cmp1(node x, node y) { return x.x < y.x; };
bool cmp2(node x, node y) { return x.y < y.y; };
bool cmp3(node x, node y) {
  if (x.x == y.x)
    return x.y < y.y;
  else
    return x.x < y.x;
}
long long judge() {
  long long ans = 1, cnt = 1;
  sort(a + 1, a + 1 + n, cmp3);
  for (int i = 1; i < n; i++)
    if (a[i].y > a[i + 1].y) return 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y)
      cnt++;
    else {
      ans = ans * sui[cnt] % mod;
      cnt = 1;
    }
  }
  ans = (ans * sui[cnt]) % mod;
  return ans;
}
long long slove1() {
  int num = 0, pre = a[1].x;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i].x == pre)
      num++;
    else {
      pre = a[i].x;
      ans = (ans * sui[num]) % mod;
      num = 1;
    }
  }
  ans = (ans * sui[num]) % mod;
  return ans;
}
long long slove2() {
  int num = 0, pre = b[1].y;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (b[i].y == pre)
      num++;
    else {
      pre = a[i].y;
      ans = (ans * sui[num]) % mod;
      num = 1;
    }
  }
  ans = (ans * sui[num]) % mod;
  return ans;
}
int main() {
  int t;
  cin >> n;
  long long cnt = 1;
  for (int i = 1; i <= n; i++) {
    cnt = (cnt * i) % mod;
    sui[i] = cnt;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + n, cmp1);
  sort(b + 1, b + 1 + n, cmp2);
  long long ans = sui[n] - slove1() - slove2() + judge();
  ans = ans + mod * 3 % mod;
  cout << ans << endl;
}
