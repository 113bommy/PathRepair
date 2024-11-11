#include <bits/stdc++.h>
using namespace std;
int markd[1001];
int markcd[1001][1001];
int capd[1001];
int capcd[1001][1001];
int main() {
  int n;
  int m;
  cin >> n >> m;
  int x;
  int y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    markd[y]++;
    markcd[x][y]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    capd[y]++;
    capcd[x][y]++;
  }
  int m1 = 0;
  int m2 = 0;
  for (int i = 0; i < 1001; i++) {
    if (markd[i] > 0 && capd[i] > 0) {
      m1 = m1 + min(markd[i], capd[i]);
      for (int j = 0; j < 1001; j++) {
        if (markcd[j][i] > 0 && capcd[j][i] > 0) {
          m2 = m2 + min(markcd[j][i], capcd[j][i]);
        }
      }
    }
  }
  cout << m1 << " " << m2;
  return 0;
}
