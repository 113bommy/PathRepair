#include <bits/stdc++.h>
using namespace std;
long long xx[105], yy[105], cnt;
long long gcd(long long x, long long y) {
  int res = (y == 0 ? x : gcd(y, x % y));
  xx[++cnt] = x;
  yy[cnt] = y;
  return res;
}
long long ans[105];
bool check(long long a, long long b) {
  if (a % 2 == 1) {
    return (b / a - 1) % 2;
  } else {
    if (a >= 1000000001 || b <= a * a) {
      return !((b / a) % 2);
    } else {
      long long res = b / a;
      long long c1 = (res % (a + 1)) % 2;
      long long c2 = res % (a + 1);
      return !c1 && (c2 != a);
    }
  }
}
void solve(long long a, long long b) {
  cnt = 0;
  gcd(a, b);
  ans[1] = 0;
  for (int i = 2; i <= cnt; i++) {
    if (ans[i - 1] == 0)
      ans[i] = 1;
    else if (check(yy[i], xx[i] - yy[i - 1]))
      ans[i] = 1;
    else
      ans[i] = 0;
  }
  if (ans[cnt])
    printf("First\n");
  else
    printf("Second\n");
}
int p = 12;
int biao[100005];
int dabiao(int x) {
  if (biao[x] != -1) return biao[x];
  if (x < 0) return 0;
  int temp = p;
  int flag = 0;
  while (temp <= x * p) {
    if (dabiao(x - temp / p) == 0) {
      flag = 1;
      break;
    }
    temp *= p;
  }
  return biao[x] = flag;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (b == 0)
      cout << "Second" << endl;
    else if (a % b == 0)
      cout << "First" << endl;
    else
      solve(a, b);
  }
  return 0;
}
