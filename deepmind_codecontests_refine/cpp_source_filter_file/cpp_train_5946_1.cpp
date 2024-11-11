#include <bits/stdc++.h>
using namespace std;
long long sum[300000 + 5];
int cows[300000 + 5];
long long ans[300000 + 5];
pair<pair<int, int>, int> vec[300000 + 5];
void calc(int b, int n) {
  for (int a = n; a >= 1; --a)
    if (a + b <= n)
      sum[a] = sum[a + b] + cows[a - 1];
    else
      sum[a] = cows[a - 1];
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &cows[i]);
  int p;
  scanf("%d", &p);
  for (int i = 0; i < p; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    vec[i] = make_pair(pair<int, int>(b, a), i);
  }
  sort(vec, vec + p);
  const int TH = 500;
  int b0 = -1;
  int i;
  for (i = 0; i < p; ++i) {
    int a, b;
    b = vec[i].first.first;
    a = vec[i].first.second;
    int idx = vec[i].second;
    if (b >= TH) break;
    if (b != b0) {
      calc(b, n);
      b0 = b;
    }
    ans[idx] = sum[a];
  }
  for (; i < p; ++i) {
    int a, b;
    b = vec[i].first.first;
    a = vec[i].first.second;
    int idx = vec[i].second;
    long long res = 0LL;
    for (int k = a; k <= n; k += b) res += cows[k - 1];
    ans[idx] = res;
  }
  for (int i = 0; i < p; ++i) {
    printf("%lld\n", ans[i]);
  }
}
int main() { solve(); }
