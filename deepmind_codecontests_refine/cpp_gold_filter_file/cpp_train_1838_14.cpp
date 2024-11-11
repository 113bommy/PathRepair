#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
inline int ab(int x) { return x >= 0 ? x : -x; }
long long ans[1000], b[1000];
int main() {
  long long p, k, tot = 0;
  scanf("%I64d%I64d", &p, &k);
  while (p) {
    ans[++tot] = -p / k;
    if (ans[tot] * k < -p) ans[tot]++;
    b[tot] = ans[tot] * k + p;
    p = ans[tot];
  }
  cout << tot << endl;
  for (int i = 1; i <= tot; ++i) printf("%I64d%c", b[i], " \n"[i == tot]);
  return 0;
}
