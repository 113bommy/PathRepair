#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5002;
const long long INF = 1e15 + 9;
long long x[MAX_N];
long long a[MAX_N];
long long b[MAX_N];
long long c[MAX_N];
long long d[MAX_N];
long long f(int i, int j) {
  if (j < i)
    return abs(x[i] - x[j]) + c[i] + b[j];
  else
    return abs(x[i] - x[j]) + d[i] + a[j];
}
int Next[MAX_N];
int main() {
  int n, s, e;
  while (scanf("%d %d %d", &n, &s, &e) != EOF) {
    for (int i = 1; n >= i; i++) scanf("%d", &x[i]);
    for (int i = 1; n >= i; i++) scanf("%d", &a[i]);
    for (int i = 1; n >= i; i++) scanf("%d", &b[i]);
    for (int i = 1; n >= i; i++) scanf("%d", &c[i]);
    for (int i = 1; n >= i; i++) scanf("%d", &d[i]);
    Next[s] = e;
    long long sum = f(s, e);
    for (int i = 1; n >= i; i++) {
      if (i != s && i != e) {
        int id = -1;
        long long mn = INF;
        for (int j = s; j != e; j = Next[j]) {
          long long tmp = f(j, i) + f(i, Next[j]) - f(j, Next[j]);
          if (tmp < mn) {
            mn = tmp;
            id = j;
          }
        }
        sum += mn;
        Next[i] = Next[id];
        Next[id] = i;
      }
    }
    printf("%d\n", sum);
  }
}
