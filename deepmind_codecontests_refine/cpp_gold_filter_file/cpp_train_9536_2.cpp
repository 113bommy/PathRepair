#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
int ac[MAXN], ab[MAXN], ba[MAXN], bc[MAXN], ca[MAXN], cb[MAXN];
long long pre[MAXN];
int n, p, q, r;
int main() {
  scanf("%d%d%d%d", &n, &p, &q, &r);
  for (int i = (0); i < (n); i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ac[a] = max(ac[a], c);
    ab[a] = max(ab[a], b);
    bc[b] = max(bc[b], c);
    ba[b] = max(ba[b], a);
    ca[c] = max(ca[c], a);
    cb[c] = max(cb[c], b);
  }
  for (int i = (p)-1; i >= (1); i--)
    ac[i] = max(ac[i], ac[i + 1]), ab[i] = max(ab[i], ab[i + 1]);
  for (int i = (q)-1; i >= (1); i--)
    ba[i] = max(ba[i], ba[i + 1]), bc[i] = max(bc[i], bc[i + 1]);
  for (int i = (r)-1; i >= (1); i--)
    ca[i] = max(ca[i], ca[i + 1]), cb[i] = max(cb[i], cb[i + 1]);
  long long ans = 1ll * p * q * r;
  for (int i = (1); i < (p + 1); i++) ans -= 1ll * ac[i] * q;
  for (int i = (1); i < (p + 1); i++) ans -= 1ll * ab[i] * r;
  for (int i = (1); i < (q + 1); i++) {
    ans -= 1ll * bc[i] * p;
  }
  for (int i = (1); i < (p + 1); i++) ans += 1ll * ac[i] * ab[i];
  for (int i = (1); i < (q + 1); i++) ans += 1ll * bc[i] * ba[i];
  for (int i = (1); i < (r + 1); i++) ans += 1ll * cb[i] * ca[i];
  for (int i = (1); i < (r + 1); i++) pre[i] = pre[i - 1] + cb[i];
  for (int i = (1); i < (p + 1); i++) {
    int xy = ab[i], xz = ac[i];
    if (bc[xy] >= xz)
      ans -= 1ll * xz * xy;
    else
      ans -= 1ll * bc[xy] * xy + pre[xz] - pre[bc[xy]];
  }
  cout << ans << endl;
}
