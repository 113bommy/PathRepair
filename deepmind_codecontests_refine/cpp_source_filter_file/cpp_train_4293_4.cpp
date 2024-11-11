#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int eps = 1e-8;
const long long mod = 1e9 + 7;
const long long maxn = 100 + 10;
const unsigned long long modd = 212370440130137957ll;
const long long Mod = 998244353;
int lowbit(int x) { return x & -x; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long quick_power(long long a, long long b, long long c) {
  long long ans = 1;
  a = a % c;
  while (b) {
    if (b & 1) ans = (ans * a) % c;
    b = b >> 1;
    a = (a * a) % c;
  }
  return ans;
}
bool isprime(int x) {
  int flag = 1;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      flag = 0;
      break;
    }
  }
  if (flag)
    return 1;
  else
    return 0;
}
int t;
int b[maxn];
int flag[maxn];
int flag1[maxn];
int a[maxn];
int ans[maxn];
int maxx;
int minn;
int main(int argc, char const *argv[]) {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    minn = INF;
    maxx = 0;
    memset(flag, 0, sizeof(flag));
    memset(flag1, 0, sizeof(flag1));
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      flag[b[i]] = 1;
      maxx = max(maxx, b[i]);
      minn = min(minn, b[i]);
    }
    if (maxx == 2 * n || minn != 1) {
      cout << -1 << endl;
      continue;
    }
    int k = 1;
    for (int i = 1; i <= 2 * n; i++) {
      if (!flag[i]) {
        a[k] = i;
        k++;
      }
    }
    sort(a + 1, a + 1 + n);
    int tmp = 1;
    int flag4 = 0;
    for (int i = 1; i <= n; i++) {
      int flag2 = 0;
      ans[tmp++] = b[i];
      for (int j = 1; j <= n; j++) {
        if (a[j] > b[i] && !flag1[a[j]]) {
          ans[tmp++] = a[j];
          flag2 = 1;
          flag1[a[j]] = 1;
          break;
        }
      }
      if (flag2 == 0) {
        flag4 = 1;
        cout << -1;
        break;
      }
    }
    if (flag4 == 0)
      for (int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << " ";
      }
    else
      cout << endl;
  }
  return 0;
}
