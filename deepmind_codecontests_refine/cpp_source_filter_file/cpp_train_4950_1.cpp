#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const int MAX = (int)1e5 + 5;
void build() { return; }
long long n, k;
long long store[MAX];
void Init() {
  scanf("%lld %lld", &n, &k);
  for (int i = (1); i < (n + 1); ++i) scanf("%lld", store + i);
  return;
}
inline long long gcd(long long v1, long long v2) {
  while (v1 != 0) {
    long long tmp = v2 % v1;
    v2 = v1;
    v1 = tmp;
  }
  return v2;
}
void sol() {
  for (int i = (1); i < (n + 1); ++i) store[i] = gcd(store[i], k);
  long long cur = 1;
  for (int i = (1); i < (n + 1); ++i) {
    cur = cur * store[i] / gcd(cur, store[i]);
    if (cur % k == 0) {
      puts("Yes");
      return;
    }
  }
  puts("No");
  return;
}
int main(void) {
  Init();
  build();
  sol();
  return 0;
}
