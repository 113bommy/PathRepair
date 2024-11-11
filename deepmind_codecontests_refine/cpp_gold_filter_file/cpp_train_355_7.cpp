#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int in[N];
pair<int, int> p[N];
int nxt[N], prv[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", in + i);
    p[i] = {in[i], i};
    nxt[i] = i + 1;
    prv[i] = i - 1;
  }
  sort(p, p + n);
  long long res = 0;
  int low = 0, high = n - 1;
  for (int i = 0; i < n - 2; ++i) {
    int j = p[i].second;
    if (j == low) {
      res += p[i].first;
      low = nxt[low];
      continue;
    }
    if (j == high) {
      res += p[i].first;
      high = prv[high];
      continue;
    }
    int x = in[prv[j]];
    int y = in[nxt[j]];
    res += min(x, y);
    nxt[prv[j]] = nxt[j];
    prv[nxt[j]] = prv[j];
  }
  printf("%lld\n", res);
}
