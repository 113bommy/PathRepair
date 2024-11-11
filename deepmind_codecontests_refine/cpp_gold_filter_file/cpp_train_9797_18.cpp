#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
int main() {
  cin >> n >> k;
  int N = n;
  int l = (n + 2 * k) / (2 * k + 1);
  n -= l * (k + 1);
  int cnt = 0;
  while (n) {
    int now = min(n, k);
    v.push_back(now + k + 1);
    n -= now;
    cnt++;
  }
  for (int i = 0; i < l - cnt; i++) v.push_back(k + 1);
  printf("%d\n", l);
  if (l == 1) {
    printf("%d", (N + 1) / 2);
  } else if (l == 2) {
    printf("%d %d", v[0] - k, N + 1 + k - v[1]);
  } else {
    printf("%d ", v.back() - k);
    int now = v.back() - k;
    for (int i = 0; i < l - 2; i++) {
      now += (2 * k + 1);
      printf("%d ", now);
    }
    printf("%d", N + 1 + k - v[v.size() - 2]);
  }
  return 0;
}
