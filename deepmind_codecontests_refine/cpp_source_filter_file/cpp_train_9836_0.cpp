#include <bits/stdc++.h>
using namespace std;
int const N = 200001;
int n, w[N], h[N], hh[N], fr[N];
vector<int> mx;
int main() {
  scanf("%d", &n);
  int W = 0;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", w + i, h + i);
    W += w[i];
    m = max(m, h[i]);
    hh[i] = h[i];
    ++fr[h[i]];
  }
  sort(hh, hh + n);
  reverse(hh, hh + n);
  int nm = 0, j = -1;
  for (int i = 0; i < n; ++i)
    if (h[i] != m) {
      nm = h[i];
      break;
    }
  for (int i = 0; i < n; ++i) {
    long long pix = W - w[i];
    if (h[i] == m && fr[h[i]] - 1)
      pix *= h[i];
    else {
      if (h[i] != m)
        pix *= m;
      else
        pix *= nm;
    }
    printf("%lld ", pix);
  }
}
