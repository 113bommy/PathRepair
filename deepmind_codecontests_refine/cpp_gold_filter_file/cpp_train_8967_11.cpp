#include <bits/stdc++.h>
using namespace std;
long long MOD(long long a) {
  if (a >= 1000003) return a % 1000003;
  if (a < 0) return a % 1000003 + 1000003;
  return a;
}
long long bp(long long a, long long b) {
  long long ans = 1, res = a, i;
  for (i = 1; i <= b; i <<= 1, res = MOD(res * res)) {
    if (b & i) ans = MOD(ans * res);
  }
  return ans;
}
long long inv(long long a) { return bp(a, 1000003 - 2); }
vector<long long> res_mul;
void multiply(vector<long long> *a, vector<long long> *b,
              vector<long long> *c) {
  res_mul.resize(a->size() + b->size() - 1);
  res_mul.assign(a->size() + b->size() - 1, 0);
  int i, j;
  for (i = 0; i < a->size(); i++) {
    for (j = 0; j < b->size(); j++) {
      res_mul[i + j] = MOD(res_mul[i + j] + (*a)[i] * (*b)[j]);
    }
  }
  while (res_mul[res_mul.size() - 1] == 0) res_mul.pop_back();
  c->resize(res_mul.size());
  for (i = 0; i < res_mul.size(); i++) (*c)[i] = res_mul[i];
}
long long ans[15], co[15];
void interpolate() {
  int i, j;
  vector<long long> res, mul;
  mul.resize(2, 0);
  for (i = 0; i <= 10; i++) {
    long long d = ans[i];
    res.resize(1);
    res[0] = 1;
    for (j = 0; j <= 10; j++) {
      if (i == j) continue;
      d = MOD(d * inv(i - j));
      mul[0] = -j;
      mul[1] = 1;
      multiply(&res, &mul, &res);
    }
    for (j = 0; j < res.size(); j++) co[j] = MOD(co[j] + res[j] * d);
  }
}
int main() {
  int n, i, j;
  for (i = 0; i <= 10; i++) {
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%lld", &ans[i]);
  }
  interpolate();
  for (i = 0; i < 1000003; i++) {
    long long res = 0;
    for (j = 10; j >= 0; j--) {
      res = MOD(res * i + co[j]);
    }
    if (res == 0) {
      printf("! %d\n", i);
      return 0;
    }
  }
  printf("! -1\n");
  return 0;
}
