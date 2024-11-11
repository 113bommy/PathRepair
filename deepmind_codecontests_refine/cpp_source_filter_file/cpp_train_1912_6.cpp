#include <bits/stdc++.h>
const long long oo = 10001;
using namespace std;
int main() {
  int n = 0, m = 0;
  int M[101][oo] = {}, dist[101][oo] = {};
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    char line[oo];
    scanf("%s", line);
    int dst = 5 * oo;
    for (int j = 0; j < m; j++) {
      M[i][j] = (int)(line[j] == '1');
      if (M[i][j]) {
        dst = 0;
      }
      dist[i][j] = dst;
      dst++;
    }
    for (int j = 0; j < m; j++) {
      if (M[i][j]) {
        dst = 0;
      }
      dist[i][j] = min(dst, dist[i][j]);
      dst++;
    }
    dst = 5 * oo;
    for (int j = m - 1; j >= 0; j--) {
      if (M[i][j]) {
        dst = 0;
      }
      dist[i][j] = min(dst, dist[i][j]);
      dst++;
    }
    for (int j = m - 1; j >= 0; j--) {
      if (M[i][j]) {
        dst = 0;
      }
      dist[i][j] = min(dst, dist[i][j]);
      dst++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (dist[i][0] == 5 * oo) {
      cout << -1 << endl;
      return 0;
    }
  }
  int answ = 5 * oo;
  for (int j = 0; j < m; j++) {
    int tmpAnsw = 0;
    for (int i = 0; i < n; i++) {
      tmpAnsw += dist[i][j];
    }
    answ = min(answ, tmpAnsw);
  }
  cout << answ << endl;
  return 0;
}
