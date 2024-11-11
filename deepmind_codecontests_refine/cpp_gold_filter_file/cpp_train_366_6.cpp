#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, MAXL = 40;
const long long INF = 4e18;
int n;
long long m;
int maxl;
int pai[MAXN][MAXL];
long long lessy[MAXN][MAXL];
long long sum[MAXN][MAXL];
void build() {
  maxl = log2(m) + 1;
  for (int l = 1; l <= maxl; l++) {
    for (int i = 0; i < n; i++) {
      pai[i][l] = pai[pai[i][l - 1]][l - 1];
      sum[i][l] = sum[pai[i][l - 1]][l - 1] + sum[i][l - 1];
      lessy[i][l] = min(lessy[pai[i][l - 1]][l - 1], lessy[i][l - 1]);
    }
  }
}
int main() {
  scanf("%d %lld", &n, &m);
  for (int i = 0, a; i < n; i++) scanf("%d", &a), pai[i][0] = a;
  long long b;
  for (int i = 0, b; i < n; i++) scanf("%lld", &b), lessy[i][0] = sum[i][0] = b;
  build();
  for (int i = 0; i < n; i++) {
    long long jump = m;
    int cur = i;
    long long lessy0 = INF, sum0 = 0;
    for (int l = maxl; jump && l >= 0; l--) {
      if ((1LL << l) <= jump) {
        lessy0 = min(lessy0, lessy[cur][l]);
        sum0 += sum[cur][l];
        cur = pai[cur][l];
        jump -= (1LL << l);
      }
    }
    printf("%lld %lld\n", sum0, lessy0);
  }
}
