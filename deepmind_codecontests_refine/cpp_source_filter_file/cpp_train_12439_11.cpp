#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int N = 5000000;
int cnt[N + 7];
bool pri[N + 7];
void check_prime() {
  fill(&pri[0], &pri[N + 1], true);
  pri[0] = false;
  pri[1] = false;
  int x = 2;
  while (x <= N) {
    for (int m = 2; m * x <= N; ++m) {
      pri[m * x] = false;
    }
    ++x;
    while (!pri[x]) ++x;
  }
}
int calc(int x) {
  int &res = cnt[x];
  if (res != 0) return cnt[x];
  if (pri[x]) return res = cnt[x] = 1;
  res = 1;
  for (int d = 2; d * d <= x; ++d) {
    if (pri[d] && x % d == 0) return res = calc(x / d) + 1;
  }
  return res;
}
int main() {
  check_prime();
  memset(cnt, 0, sizeof(cnt));
  for (int x = 2; x <= N; ++x) {
    calc(x);
  }
  vector<long long> sum(N + 1);
  sum[0] = sum[1] = 0;
  for (int x = 2; x <= N; ++x) {
    sum[x] = sum[x - 1] + cnt[x];
  }
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("I64d\n", sum[a] - sum[b]);
  }
  return 0;
}
