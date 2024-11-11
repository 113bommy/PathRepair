#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tos(T a) {
  stringstream ss;
  string ret;
  ss << a;
  ss >> ret;
  return ret;
}
vector<long long> luck;
int llen;
void gen(long long v) {
  if (v > 1000000000) return;
  luck.push_back(v);
  gen(v * 10 + 4);
  gen(v * 10 + 7);
}
long long get(long long a, long long b, long long c, long long d, long long k) {
  long long ret = 0;
  long long na, nb, nc, nd;
  for (int(i) = (0); (i) < (llen); (i)++) {
    int j = i + k - 1;
    if (j >= llen) break;
    na = a;
    nb = b;
    nc = c;
    nd = d;
    if (i > 0) na = max(na, luck[i - 1] + 1);
    nb = min(nb, luck[i]);
    nc = max(nc, luck[j]);
    if (j != llen - 1) nd = min(nd, luck[j + 1] - 1);
    if (na <= nb && nc <= nd) ret += (nb - na + 1) * (nd - nc + 1);
  }
  return ret;
}
int main() {
  long long a, b, c, d, k;
  gen(4);
  gen(7);
  sort(luck.begin(), luck.end());
  llen = luck.size();
  while (cin >> a >> b >> c >> d >> k) {
    long long ret = 0;
    ret = get(a, b, c, d, k) + get(c, d, a, b, k);
    if (k == 1)
      for (int(i) = (0); (i) < (llen); (i)++)
        if (luck[i] >= a && luck[i] <= b && luck[i] >= c && luck[i] <= d) ret--;
    long long tot = (b - a + 1) * (d - c + 1);
    double res = ret / (double)tot;
    printf("%.12lf\n", res);
  }
  return 0;
}
