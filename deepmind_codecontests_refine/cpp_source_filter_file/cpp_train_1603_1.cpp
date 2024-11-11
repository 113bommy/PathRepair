#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
const int maxm = 2e5 + 5;
int n, m, ans, a[maxn], b[maxn], l[maxn], nxt[maxn], cnt[maxn];
bool used[maxn];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", a + i, l + i);
    b[i] = a[i] + l[i];
    cnt[a[i]]++;
    nxt[a[i]] = max(nxt[a[i]], b[i]);
  }
  for (int i = 1, fir = 0, farth, k = 0; i <= n; i++) {
    if (!fir) {
      while (!cnt[i]) i++;
      fir = 1;
    }
    ans++, used[i] = 1, farth = nxt[i], k = 0;
    for (int j = i + 1; j <= farth; j++) {
      if (nxt[j] > farth && cnt[i]) {
        farth = nxt[j];
        k = j;
      }
    }
    if (k) {
      i = k - 1;
    } else {
      i = nxt[i] + 1;
      while (!cnt[i] && i <= n + 1) i++;
      i--;
    }
  }
  printf("%d\n", m - ans);
  for (int i = 1; i <= m; i++) {
    if (used[a[i]]) {
      if (nxt[a[i]] ^ b[i])
        printf("%d ", i);
      else
        used[a[i]] = 0;
    } else
      printf("%d ", i);
  }
  return 0;
}
