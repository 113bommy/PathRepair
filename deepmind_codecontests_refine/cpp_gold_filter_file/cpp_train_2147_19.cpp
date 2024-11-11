#include <bits/stdc++.h>
using namespace std;
int n;
long long c[100001], r[100001];
void process(long long c[], int k, int t) {
  int ql = min(k, n);
  long long q[ql];
  for (int i = 0; i < ql; i++) q[i] = 1;
  for (int i = 0; i < n; i++) {
    int j = i % ql;
    if (c[i] >= q[j])
      r[i] = c[i] + t;
    else
      r[i] = q[j] + t;
    q[j] = r[i];
  }
}
int main() {
  int k[3];
  for (int i = 0; i < 3; i++) cin >> k[i];
  int t[3];
  for (int i = 0; i < 3; i++) cin >> t[i];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  process(c, k[0], t[0]);
  process(r, k[1], t[1]);
  process(r, k[2], t[2]);
  long long maxd = 0;
  for (int i = 0; i < n; i++) maxd = max(maxd, r[i] - c[i]);
  cout << maxd;
  return 0;
}
