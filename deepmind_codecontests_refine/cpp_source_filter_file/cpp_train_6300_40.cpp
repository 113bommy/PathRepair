#include <bits/stdc++.h>
using namespace std;
long double po(long double x, int n) {
  long double ret = 1;
  while (n) {
    if (n & 1) ret = ret * x;
    x = x * x;
    n >>= 1;
  }
  return ret;
}
int N;
int P[102], C[102];
long double mul, X[102];
priority_queue<pair<long double, int> > pq;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }
  long double ans = 0;
  long double mul = 1;
  for (int i = 0; i < N; i++) {
    X[i] = (long double)P[i] / 100;
    C[i] = 1;
    mul *= X[i];
    pq.push(make_pair((1 - po(1 - (long double)P[i] / 100, C[i] + 1)) /
                          (1 - po(1 - (long double)P[i] / 100, C[i])),
                      i));
  }
  long double tmp = 0;
  for (int i = N; i < 100000; i++) {
    ans += (mul - tmp) * i;
    tmp = mul;
    long double p = pq.top().first;
    int id = pq.top().second;
    pq.pop();
    X[id] *= p;
    C[id]++;
    mul *= p;
    pq.push(make_pair((1 - po(1 - (long double)P[id] / 100, C[id] + 1)) /
                          (1 - po(1 - (long double)P[id] / 100, C[id])),
                      id));
  }
  cout << fixed;
  cout.precision(20);
  cout << ans;
}
