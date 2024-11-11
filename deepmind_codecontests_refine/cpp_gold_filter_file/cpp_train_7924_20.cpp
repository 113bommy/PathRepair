#include <bits/stdc++.h>
using namespace std;
void generate(long long x, vector<int>& res) {
  if (x <= 1000000000) {
    if (x) res.push_back(x);
    long long a = 10LL * x + 4;
    long long b = 10LL * x + 7;
    generate(a, res);
    generate(b, res);
  }
}
vector<int> vec;
double prob(int a, int b, int l, int r) {
  int ca = max(a, l);
  int cb = min(b, r);
  if (cb < ca) return 0.0;
  return double(cb - ca + 1) / double(r - l + 1);
}
int main() {
  generate(0, vec);
  sort(vec.begin(), vec.end());
  int n = (int)vec.size();
  int pl, pr, vl, vr, k;
  cin >> pl >> pr >> vl >> vr >> k;
  double res = 0;
  for (int i = 0; i < (n - k + 1); ++i) {
    int a = (i == 0) ? 1 : vec[i - 1] + 1;
    int b = vec[i];
    int c = vec[i + k - 1];
    int d = (i + k >= n) ? 1000000000 : vec[i + k] - 1;
    res += prob(a, b, vl, vr) * prob(c, d, pl, pr);
    res += prob(a, b, pl, pr) * prob(c, d, vl, vr);
    if (b == c && k == 1) res -= prob(b, b, vl, vr) * prob(c, c, pl, pr);
  }
  printf("%.9lf\n", res);
  return 0;
}
