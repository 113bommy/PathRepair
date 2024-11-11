#include <bits/stdc++.h>
using namespace std;
long long fun(long long X, long long M) {
  long long t1, t2, t3;
  t1 = M * (M + 1) / 2;
  t2 = M * (M + 1) * (2 * M + 1) / 6;
  t3 = (M) * (M + 1) / 2;
  long long t4, t5, t6;
  t4 = (t2 - t3) / 2;
  t5 = X + t4;
  if (t5 % t1 == 0) {
    long long a = t5 / t1;
    if (a < M)
      return -1;
    else
      return a;
  }
  return -1;
}
int main() {
  long long X;
  scanf("%lld", &X);
  set<pair<long long, long long> > S;
  S.clear();
  long long i;
  for (i = 1; i < sqrt(X); i++) {
    long long n = fun(X, i);
    if (n != -1) {
      S.insert(make_pair(i, n));
      S.insert(make_pair(n, i));
    }
  }
  printf("%lld\n", S.size());
  for (set<pair<long long, long long> >::iterator it = S.begin(); it != S.end();
       it++) {
    printf("%lld %lld\n", (it)->first, (it)->second);
  }
}
