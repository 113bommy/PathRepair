#include <bits/stdc++.h>
using namespace std;
int lab[112345], a[112345], b[112345];
long long sum[112345], res[112345];
int n;
bool dd[112345];
int getroot(int u) {
  if (u == lab[u]) return u;
  lab[u] = getroot(lab[u]);
  return lab[u];
}
void join(int u, int v) {
  sum[getroot(v)] += sum[getroot(u)];
  lab[lab[u]] = lab[v];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    lab[i] = i;
    sum[i] = a[i];
  }
  for (int i = n; i >= 1; i--) {
    res[i] = res[i + 1];
    dd[b[i]] = true;
    if (b[i] > 1 && dd[b[i] - 1]) join(b[i], b[i] - 1);
    if (b[i] < n && dd[b[i] + 1]) join(b[i], b[i] + 1);
    res[i] = max(res[i], sum[getroot(b[i])]);
  }
  for (int i = 2; i <= n + 1; i++) printf("%I64d\n", res[i]);
}
