#include <bits/stdc++.h>
using namespace std;
namespace io {
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
}  // namespace io
using namespace io;
const long double PI = 4 * atan((long double)1);
void yn(bool y) { printf("%s\n", y ? "YES" : "NO"); }
void p(int x) { printf("%d\n", x); }
void p(long long x) { printf("%I64d\n", x); }
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int m = 1;
    while (m * (m - 1) < n) {
      m++;
    }
    p(m);
    int k = n;
    for (int i = 1; i <= m && k > 0; i++, k--) {
      printf("%d %d\n", 1, i);
    }
    for (int i = 2; i <= m && k > 0; i++, k--) {
      printf("%d %d\n", i, m);
    }
  }
  return 0;
}
