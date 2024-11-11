#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
struct sta {
  int val;
  int id;
  bool operator<(const sta& rhs) const { return val > rhs.val; }
} a[maxn];
bool ans[maxn];
int main() {
  int n = read();
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    a[i].val = read();
    sum += a[i].val;
    a[i].id = i;
  }
  long long l = (sum - a[1].val - 1) / 2 + 1, r = sum + a[1].val >> 1;
  sort(a + 1, a + n + 1);
  long long tmp = 0;
  for (int i = 1; i <= n; i++) {
    if (tmp + a[i].val <= r) {
      tmp += a[i].val;
      ans[a[i].id] = 1;
    }
  }
  bool flag = 0;
  if (sum > tmp * 2) flag = 1;
  for (int i = 1; i <= n; i++) printf("%c", (ans[i] ^ flag) ? '+' : '-');
  return 0;
}
