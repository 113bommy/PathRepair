#include <bits/stdc++.h>
using namespace std;
int f[2][200001];
int L[200001], R[200001];
int main() {
  int n, K;
  cin >> n >> K;
  for (int i = 1; i <= K; i++) cin >> L[i] >> R[i];
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  deque<int> q1, q2;
  int cur = 0;
  for (int i = 1; i <= K; i++) {
    q1.clear();
    q2.clear();
    for (int j = 0; j <= n; j++) f[!cur][j] = f[cur][j];
    for (int j = 0; j <= min(n, R[i]); j++) {
      while (!q1.empty() && j - L[i] + R[i] > q1.front()) q1.pop_front();
      while (!q1.empty() && f[cur][j] <= f[cur][q1.back()]) q1.pop_back();
      q1.push_back(j);
      f[!cur][j] = min(f[!cur][j], f[cur][q1.front()] + 2);
    }
    for (int j = R[i]; j >= 0; j--) {
      while (!q2.empty() && L[i] - j > q2.front()) q2.pop_front();
      while (!q2.empty() && f[cur][R[i] - j] <= f[cur][q2.back()])
        q2.pop_back();
      q2.push_back(R[i] - j);
      f[!cur][j] = min(f[!cur][j], f[cur][q2.front()] + 1);
    }
    cur = !cur;
  }
  if (f[cur][n] >= 1e7)
    cout << "Hungry\n";
  else
    cout << "Full\n" << f[cur][n] << endl;
}
