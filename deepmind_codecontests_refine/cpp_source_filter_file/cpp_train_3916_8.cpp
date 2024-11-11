#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long a[20000];
long long b[20000];
int main() {
  if (fopen("/home/lianyi/123.txt", "r") != NULL) {
    freopen("/home/lianyi/123.txt", "r", stdin);
  } else {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
  }
  long long n, k;
  while (cin >> n >> k) {
    long long need = 0;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    int n4 = n;
    int n2 = 2 * n;
    for (int i = 1; i <= k; i++) {
      int x = a[i] / 4;
      a[i] -= 4 * x;
      if (n4 >= x) {
        n4 -= x;
      } else {
        n2 -= 2 * (x - n4);
        n4 = 0;
      }
    }
    for (int i = 1; i <= k; i++) {
      if (a[i] == 3) {
        if (n4 > 0) {
          n4--;
        } else {
          n2 -= 2;
        }
        a[i] = 0;
      }
    }
    int cnt = 0;
    queue<int> que1, que2;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= k; i++) {
      if (a[i] == 1) c1++;
      if (a[i] == 2) c2++;
    }
    int tmp;
    int c12 = min(c1, c2);
    c1 -= c12;
    c2 -= c12;
    tmp = min(c12, n4);
    n4 -= tmp;
    n2 -= 2 * (c12 - tmp);
    int c;
    c = c2 / 3;
    c2 -= 3 * c;
    tmp = min(2 * c, n4 / 2);
    n4 -= tmp * 2;
    n2 -= (c * 3 - tmp * 3);
    int x = c1 / 2;
    c1 -= x * 2;
    if (n4 >= x) {
      n4 -= x;
    } else {
      n2 -= x * 3 - n4 * 2;
      n4 = 0;
    }
    int mx = min(n4, c1);
    n4 -= mx;
    c1 -= mx;
    n2 -= c1;
    mx = min(n4, c2);
    n4 -= mx;
    c2 -= mx;
    n2 -= c2;
    n2 += n4;
    if (n4 >= 0 && n2 >= 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
