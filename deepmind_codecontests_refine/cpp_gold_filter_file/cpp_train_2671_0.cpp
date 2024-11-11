#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<long long> dv;
long long sqrtt(long long num) {
  long long c = sqrt(num);
  if (c * c > num) c--;
  return c;
}
int main(int argc, const char* argv[]) {
  long long p = 0;
  for (long long i = 2; i <= 1000000; i++) {
    p = i * i;
    for (int j = 2; j <= 64; j++) {
      if (1e18 / p < i) break;
      p *= i;
      v.push_back(p);
    }
  }
  sort(v.begin(), v.end());
  dv.push_back(v[0]);
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == v[i - 1]) continue;
    long long q = sqrt(v[i]);
    if (!(q * q == v[i])) dv.push_back(v[i]);
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long l, r;
    scanf("%I64d%I64d", &l, &r);
    long long squareNum = (long long)sqrtt(r) - (long long)sqrtt(l);
    if (l == pow((long long)sqrtt(l), 2)) squareNum++;
    cout << squareNum + (long long)(upper_bound(dv.begin(), dv.end(), r) -
                                    lower_bound(dv.begin(), dv.end(), l))
         << endl;
  }
  return 0;
}
