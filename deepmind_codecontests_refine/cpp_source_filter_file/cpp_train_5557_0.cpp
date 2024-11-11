#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
struct node {
  long long k, a;
} nd[M], res;
bool cmp(const node &nd1, const node &nd2) { return nd1.k < nd2.k; }
int n, ek;
long long pow2[M];
long long powk(long long a, int k) {
  if (k == 0) return 1;
  long long tmp = powk(a, k / 2);
  tmp *= tmp;
  if (k % 2 == 1) return tmp * a;
  return tmp;
}
int main() {
  long long tmp, tmp2;
  int flag;
  pow2[0] = 1;
  for (int i = 1; i < 31; i++) {
    pow2[i] = pow2[i - 1] * ((long long)4);
  }
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%I64d%I64d", &nd[i].k, &nd[i].a);
    sort(nd, nd + n, cmp);
    for (int i = 0; i < n - 1; i++) {
      ek = nd[i + 1].k - nd[i].k;
      if (ek >= 30) {
        continue;
      }
      tmp = powk(8, ek);
      tmp2 = nd[i].a / tmp;
      if (nd[i].a % tmp != 0) tmp2++;
      if (tmp2 >= nd[i + 1].a) nd[i + 1].a += tmp2 - nd[i + 1].a;
    }
    flag = 0;
    for (int i = 0; i < 31; i++) {
      if (nd[n - 1].a <= pow2[i]) {
        flag = i;
        break;
      }
    }
    if (flag != 0)
      printf("%I64d\n", nd[n - 1].k + flag);
    else
      printf("%I64d\n", nd[n - 1].k + 1);
  }
  return 0;
}
