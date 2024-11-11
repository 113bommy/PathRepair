#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
int h, g, a[N];
vector<int> v;
int f(int at) {
  if (!a[at]) return 0;
  if (!a[2 * at + 1] && !a[2 * at + 2]) {
    if (at < (1 << g) - 1) return 0;
    int x = a[at];
    a[at] = 0;
    return x;
  }
  int x = f(a[2 * at + 1] > a[2 * at + 2] ? 2 * at + 1 : 2 * at + 2);
  if (!x) return 0;
  swap(a[at], x);
  return x;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    v.clear();
    long long sum = 0;
    scanf("%d%d", &h, &g);
    for (int i = 0; i < (1 << h) - 1; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    for (int i = 1 << h; i < min(N, (1 << (h + 1))); i++) a[i] = 0;
    for (int i = 0; i < (1 << h); i++) {
      int x = f(i);
      while (x) {
        sum -= x;
        v.push_back(i);
        x = f(i);
      }
    }
    printf("%lld\n", sum);
    for (auto i : v) printf("%d ", i + 1);
    puts("");
  }
}
