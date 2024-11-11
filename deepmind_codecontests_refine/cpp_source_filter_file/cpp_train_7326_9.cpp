#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Tire {
  int sz, g[maxn * 50][2];
  void init();
  void insert(long long s);
  long long find(long long s);
} T;
int N;
long long A[maxn], prefix[maxn], suffix[maxn];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
  for (int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] ^ A[i];
  for (int i = N; i; i--) suffix[i] = suffix[i + 1] ^ A[i];
  long long ans = 0;
  T.init();
  for (int i = N; i >= 0; i--) {
    T.insert(suffix[i + 1]);
    ans = max(ans, T.find(prefix[i]));
  }
  printf("%lld\n", ans);
  return 0;
}
void Tire::init() {
  sz = 1;
  memset(g[0], 0, sizeof(g[0]));
}
void Tire::insert(long long s) {
  int u = 0;
  for (int i = 40; i >= 0; i--) {
    int v = (s >> i) & 1;
    if (g[u][v] == 0) {
      memset(g[sz], 0, sizeof(g[sz]));
      g[u][v] = sz++;
    }
    u = g[u][v];
  }
}
long long Tire::find(long long s) {
  int u = 0;
  long long ret = 0;
  for (int i = 40; i >= 0; i--) {
    int v = ((s >> i) & 1) ^ 1;
    if (g[u][v])
      ret |= (1 << i);
    else
      v = v ^ 1;
    u = g[u][v];
  }
  return ret;
}
