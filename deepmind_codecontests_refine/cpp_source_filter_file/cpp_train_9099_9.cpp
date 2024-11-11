#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double tau = 2 * pi;
const double epsilon = 1e-9;
const int MAX_N = 7100;
const int MAX_M = 7100;
int N, M;
int Q[MAX_M][5];
long long sw4g[MAX_M][2];
long long nAdd(long long idx) {
  long long res = 0;
  while (idx > 0) {
    idx /= 2;
    ++res;
  }
  return res;
}
long long lowMap(long long idx, int curLevel, int targetLevel) {
  if (targetLevel == curLevel)
    return idx;
  else
    return lowMap(idx + nAdd(idx - 1), curLevel + 1, targetLevel);
}
long long highMap(long long idx, int curLevel, int targetLevel) {
  if (targetLevel == curLevel)
    return idx;
  else
    return lowMap(idx + nAdd(idx), curLevel + 1, targetLevel);
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> Q[i][0];
    int nVals;
    if (Q[i][0] == 1)
      nVals = 4;
    else
      nVals = 2;
    for (int j = 1; j <= nVals; j++) cin >> Q[i][j];
    if (Q[i][0] == 1) {
      sw4g[i][0] = lowMap(Q[i][2], Q[i][1], N);
      sw4g[i][1] = highMap(Q[i][3], Q[i][1], N);
    } else {
      long long l = lowMap(Q[i][2], Q[i][1], N);
      long long r = highMap(Q[i][2], Q[i][1], N);
      set<int> yolo;
      for (int j = 0; j < i; j++)
        if (Q[j][0] == 1)
          if (Q[j][1] >= Q[i][1])
            if (!(l > sw4g[j][1] || r < sw4g[j][0])) yolo.insert(Q[j][4]);
      cout << ((int)yolo.size()) << '\n';
    }
  }
  return 0;
}
