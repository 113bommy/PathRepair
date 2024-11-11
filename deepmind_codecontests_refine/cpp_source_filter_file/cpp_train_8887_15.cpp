#include <bits/stdc++.h>
using namespace std;
int P[510][2], L[510], fold[510], rodused[510], d[510];
int abs1(int x) { return x > 0 ? x : -1 * x; }
int dist(int i, int j) {
  if (P[i][0] == P[j][0]) return abs1(P[i][1] - P[j][1]);
  return abs1(P[i][0] - P[j][0]);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> P[i][0] >> P[i][1];
  for (int i = 0; i < m; i++) cin >> L[i];
  for (int i = 0; i < n - 1; i++) {
    d[i] = dist(i, i + 1);
  }
  d[n - 1] = dist(n - 1, 0);
  memset(rodused, 0, sizeof(rodused));
  memset(fold, -1, sizeof(fold));
  bool done = 1;
  for (int i = 1; i < n; i += 2) {
    for (int j = 0; j < m; j++) {
      if (rodused[j]) continue;
      if (d[i - 1] + d[i] == L[j]) {
        rodused[j] = 1;
        fold[i + 1] = j + 1;
        break;
      }
    }
    if (fold[i] == -1) {
      done = 0;
      break;
    }
  }
  if (!done) {
    memset(rodused, 0, sizeof(rodused));
    memset(fold, -1, sizeof(fold));
    done = 1;
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        if (rodused[j]) continue;
        int p;
        if (i == 0)
          p = d[n - 1];
        else
          p = d[i - 1];
        if (p + d[i] == L[j]) {
          rodused[j] = 1;
          fold[i] = j + 1;
          break;
        }
      }
      if (fold[i] == -1) {
        done = 0;
        break;
      }
    }
  }
  if (done) {
    cout << "YES" << endl;
    for (int i = 0; i < n - 1; i++) cout << fold[i] << " ";
    cout << fold[n - 1] << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
