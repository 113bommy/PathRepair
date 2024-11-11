#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4010;
const int MAXT = 20100;
int n, p;
int cost[MAXN], h[MAXN], t[MAXN];
int a[MAXT], b[MAXT];
vector<int> E[MAXT], Q[MAXT];
int R[MAXT];
int D2[MAXN][MAXN];
int D[MAXN];
int day[MAXN];
void pivot(int T) {
  int be = max(1, T - p), en = min(T + p - 1, MAXT);
  int c = 0;
  for (int i = T - 1; i >= be; i--) {
    for (typeof(E[i].begin()) j = E[i].begin(); j != E[i].end(); ++j) {
      day[++c] = i;
      for (int k = 1; k <= 4000; k++) {
        D2[c][k] = max(D2[c - 1][k], D2[c][k - 1]);
        if (k >= cost[*j])
          D2[c][k] = max(D2[c][k], D2[c - 1][k - cost[*j]] + h[*j]);
      }
    }
  }
  memset(D, 0, sizeof(D));
  int left = c;
  for (int i = T; i <= en; i++) {
    for (typeof(E[i].begin()) j = E[i].begin(); j != E[i].end(); ++j) {
      for (int k = 4000; k >= cost[*j]; k--)
        D[k] = max(D[k], D[k - cost[*j]] + h[*j]);
    }
    while (left && day[left] <= i - p) left--;
    for (typeof(Q[i].begin()) j = Q[i].begin(); j != Q[i].end(); ++j) {
      R[*j] = 0;
      for (int k = (0); k < (b[*j] + 1); k++)
        R[*j] = max(R[*j], D2[left][k] + D[b[*j] - k]);
    }
  }
}
int main() {
  while (cin >> n >> p) {
    memset(E, 0, sizeof(E)), memset(Q, 0, sizeof(Q));
    for (int i = (0); i < (n); i++)
      cin >> cost[i] >> h[i] >> t[i], E[t[i]].push_back(i);
    int q;
    cin >> q;
    for (int i = (0); i < (q); i++) cin >> a[i] >> b[i], Q[a[i]].push_back(i);
    for (int i = 1; i <= 20000; i += p) pivot(i);
    for (int i = (0); i < (q); i++) cout << R[i] << endl;
  }
  return 0;
}
