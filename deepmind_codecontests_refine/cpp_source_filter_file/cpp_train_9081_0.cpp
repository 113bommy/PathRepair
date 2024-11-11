#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N], b[N], a1[N];
void solve3() {
  int cnt = 0;
  string ans;
  for (;;) {
    for (int i = 0; i < n; i++) {
      if (b[i] <= 0) {
        puts("IMPOSSIBLE");
        return;
      }
    }
    if (equal(b, b + n, a)) break;
    if (equal(b, b + n, a1)) {
      ans.push_back('R');
      reverse(b, b + n);
      break;
    }
    bool inc = true, dec = true;
    for (int i = 0; i + 1 < n; i++) {
      inc = inc && a[i] < a[i + 1];
      dec = dec && a[i] > a[i + 1];
    }
    if (!inc && !dec) {
      puts("IMPOSSIBLE");
      return;
    }
    if (dec) {
      ans.push_back('R');
      reverse(b, b + n);
    }
    ++cnt;
    ans.push_back('P');
    for (int i = n - 1; i > 0; i--) b[i] -= b[i - 1];
  }
  reverse(ans.begin(), ans.end());
  if (cnt <= 200000) {
    puts("SMALL");
    printf("%d\n%s\n", (int)ans.size(), ans.c_str());
  } else {
    puts("BIG");
    printf("%d\n", cnt);
  }
}
bool ok = true;
string ans;
long long cnt = 0;
void Rev() {
  if (ok) ans.push_back('R');
}
void Rep(long long x) {
  cnt += x;
  if (ok) {
    if (cnt <= 200000) {
      for (int i = 0; i < x; i++) ans.push_back('P');
    } else {
      ok = false;
    }
  }
}
bool test(long long base, long long from, long long to) {
  return to < from && (from - to) % base == 0;
}
void solve2() {
  for (;;) {
    for (int i = 0; i < n; i++) {
      if (b[i] <= 0) {
        puts("IMPOSSIBLE");
        return;
      }
    }
    if (equal(b, b + n, a)) break;
    if (equal(b, b + n, a1)) {
      Rev();
      reverse(b, b + n);
      break;
    }
    if (b[0] == b[1]) {
      puts("IMPOSSIBLE");
      return;
    }
    if (b[0] > b[1]) {
      swap(b[0], b[1]);
      Rev();
    }
    if (a[0] == b[0] && test(b[0], b[1], a[1])) {
      Rep((b[1] - a[1]) / b[0]);
      b[1] = a[1];
    } else if (a[1] == b[0] && test(b[0], b[1], a[0])) {
      Rep((b[1] - a[0]) / b[0]);
      b[1] = a[0];
    } else {
      Rep(b[1] / b[0]);
      b[1] %= b[0];
    }
  }
  if (ok) {
    puts("SMALL");
    reverse(ans.begin(), ans.end());
    printf("%d\n%s\n", (int)ans.size(), ans.c_str());
  } else {
    printf("BIG\n%lld\n", cnt);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i), a1[i] = a[i];
  reverse(a1, a1 + n);
  for (int i = 0; i < n; i++) scanf("%lld", b + i);
  if (n == 1) {
    if (a[0] != b[0])
      puts("IMPOSSIBLE");
    else
      puts("SMALL\n0");
  } else if (n >= 3)
    solve3();
  else
    solve2();
}
