#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, k;
pair<int, int> st[MAXN];
long long d[MAXN], dd[MAXN];
long long a[MAXN], aa[MAXN], b[MAXN], bb[MAXN], c[MAXN], cc[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++) {
    scanf("%d", &st[i].first);
    st[i].second = i;
  }
  scanf("%d", &k);
  sort(st, st + n);
  for (int i = 0; i < (int)n - 1; i++) d[i] = st[i + 1].first - st[i].first;
  for (int i = 0; i < (int)n - 1; i++) {
    a[i] = d[i] * (i + 1);
    b[i] = d[i] * (n - i);
    c[i] = d[i] * (i + 1) * (n - i);
  }
  aa[0] = a[0];
  bb[0] = b[0];
  cc[0] = c[0], dd[0] = d[0];
  for (int i = 1; i < (int)n - 1; i++) {
    aa[i] = a[i] + aa[i - 1];
    bb[i] = b[i] + bb[i - 1];
    cc[i] = c[i] + cc[i - 1];
    dd[i] = d[i] + dd[i - 1];
  }
  long long ans = -1;
  int anst;
  for (int i = 0; i < (int)n - k + 1; i++) {
    long long nans = cc[i + k - 2] - cc[i] + c[i];
    long long y, x = (bb[i + k - 2] - bb[i] + b[i]) * i;
    nans = nans - x;
    x = aa[i + k - 2] - aa[i] + a[i];
    y = (dd[i + k - 2] - dd[i] + d[i]) * i;
    x = x - y;
    nans = nans - (x * (n - i - k + 1));
    if (ans == -1 || nans < ans) {
      ans = nans;
      anst = i;
    }
  }
  for (int i = anst; i < (int)anst + k; i++) printf("%d ", st[i].second + 1);
  printf("\n");
}
