#include <bits/stdc++.h>
using namespace std;
namespace I_love {
const int maxn = 10005;
const int N = 1005;
const int mod = 1e9 + 7;
int I() {
  char c;
  int x = 0, f = 1;
  while (c = getchar()) {
    if (c == '-') f = -1;
    if (isdigit(c)) break;
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
template <typename T>
void Rd(T& arg) {
  arg = I();
}
template <typename T, typename... Types>
void Rd(T& arg, Types&... args) {
  arg = I();
  Rd(args...);
}
int n, m, a[N], b[N], cnt[N];
void input() {
  Rd(n, m);
  for (int i = 1; i <= m; ++i) {
    Rd(a[i], b[i]);
    for (int day = a[i]; day <= b[i]; ++day) {
      cnt[day]++;
    }
  }
}
void run() {
  bool flag = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > 1) {
      flag = 1;
      printf("%d %d\n", i, cnt[i]);
      break;
    }
  }
  if (flag == 0) {
    puts("OK");
  }
}
void OI_Akame() {
  input();
  run();
}
}  // namespace I_love
int main() {
  I_love::OI_Akame();
  return 0;
}
