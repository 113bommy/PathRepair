#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int p = 1e9 + 7;
long long qpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * a % p;
    a = a * a % p;
    n >>= 1;
  }
  return res;
}
long long a[N], b[N];
vector<char> ans;
int n;
long long cnt = 0;
bool ok() {
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) break;
    if (i == n) return true;
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != b[n - i + 1]) return false;
  }
  ans.push_back('R');
  return true;
}
void print() {
  if (cnt <= 200000) {
    printf("SMALL\n%d\n", ans.size());
    for (int i = ans.size() - 1; i >= 0; i--) {
      printf("%c", ans[i]);
    }
    printf("\n");
  } else {
    printf("BIG\n%lld\n", cnt);
  }
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  if (n == 1) {
    if (a[1] == b[1]) {
      printf("SMALL\n0\n");
      return;
    } else {
      printf("IMPOSSIBLE\n");
      return;
    }
  }
  if (n == 2) {
    bool f = 0;
    if (a[1] > a[2]) {
      swap(a[1], a[2]);
      f = 1;
    }
    while (1) {
      if (ok()) {
        if (f) {
          ans.push_back('R');
        }
        print();
        return;
      }
      if (b[1] > b[2]) {
        swap(b[1], b[2]);
        ans.push_back('R');
      }
      if (a[1] > b[1] || a[2] > b[2]) {
        printf("IMPOSSIBLE\n");
        return;
      }
      long long tmp = max((b[2] - a[2]) / b[1], 1ll);
      cnt += tmp;
      b[2] -= b[1] * tmp;
      for (int i = 1; i <= tmp; i++) {
        if (cnt >= 200000) break;
        ans.push_back('P');
      }
    }
  }
  if (n >= 3) {
    while (1) {
      if (ok()) {
        print();
        return;
      }
      if (b[1] > b[2]) {
        for (int i = 1; i <= n / 2; i++) {
          swap(b[i], b[n - i + 1]);
        }
        ans.push_back('R');
      }
      for (int i = 3; i <= n; i++) {
        if (b[i] < b[i - 1]) {
          printf("IMPOSSIBLE\n");
          return;
        }
      }
      for (int i = n; i >= 2; i--) {
        b[i] -= b[i - 1];
      }
      ans.push_back('P');
      cnt++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    work();
  }
}
