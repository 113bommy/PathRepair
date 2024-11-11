#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int diri[4] = {-1, 0, 1, 0};
const int dirj[4] = {0, 1, 0, -1};
int N, minim[6][6], maxim[6][6], activa[6][6];
int flow[6], maxi;
void bt(int n, int m, int v) {
  if (n + 1 == N) {
    if (v > maxi) maxi = v;
    return;
  }
  if (m + 1 == N) {
    if (flow[n] < minim[n][m] or flow[n] > maxim[n][m]) return;
    int f = flow[n];
    flow[m] += f;
    flow[n] -= f;
    int vv = v;
    if (f) vv += activa[n][m] + f * f;
    bt(n + 1, n + 2, vv);
    flow[n] += f;
    flow[m] -= f;
    return;
  }
  for (int i = minim[n][m]; i <= maxim[n][m] and i <= flow[n]; ++i) {
    flow[m] += i;
    flow[n] -= i;
    int vv = v;
    if (i) vv += activa[n][m] + i * i;
    bt(n, m + 1, vv);
    flow[n] += i;
    flow[m] -= i;
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N * (N - 1) / 2; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (a > b) swap(a, b);
    cin >> minim[a][b] >> maxim[a][b] >> activa[a][b];
  }
  for (flow[0] = 1; flow[0] <= 5 * (N - 1); ++flow[0]) {
    maxi = -INF;
    bt(0, 1, 0);
    if (maxi >= 0) break;
  }
  if (maxi >= 0)
    cout << flow[0] << " " << maxi << endl;
  else
    cout << "-1 -1" << endl;
}
