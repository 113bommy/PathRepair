#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 10;
int n;
static char str[100001];
long long po(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2) x = x * y, x %= 1000000007;
    y = y * y;
    y %= 1000000007;
    b /= 2;
  }
  return x;
}
void read() { scanf("%d %s", &n, str); }
long long nCr(long long n, long long r) {
  long long ans = 1;
  for (r; r >= 1; r--) {
    ans *= n;
    ans %= 1000000007;
    n--;
    ans *= po(r, 1000000007 - 2);
    ans %= 1000000007;
    r--;
  }
  return ans;
}
void solve() {
  char c = str[0];
  bool same = true;
  for (int i = 1; i < n; i++) {
    if (c != str[i]) {
      same = false;
    }
  }
  if (same) {
    printf("1\n");
    return;
  }
  int count[26];
  for (int i = 0; i < 26; i++) count[i] = 0;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    count[str[i] - 'A']++;
    ma = max(ma, count[str[i] - 'A']);
  }
  char my[] = {'A', 'G', 'C', 'T'};
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    if (count[my[i] - 'A'] == ma) {
      cnt++;
    }
  }
  if (cnt == 1) {
    printf("1\n");
  } else if (cnt == 2) {
    printf("%lld\n", po(2, n));
  } else if (cnt == 3) {
    printf("%lld\n", po(3, n));
  } else {
    printf("%lld\n", nCr(4, n));
  }
}
int main() {
  int T = 1;
  while (T--) {
    read();
    solve();
  }
  return 0;
}
