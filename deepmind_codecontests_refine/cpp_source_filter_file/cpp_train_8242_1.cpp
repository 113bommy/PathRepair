#include <bits/stdc++.h>
using namespace std;
int const MAX_N = 1e5 + 50;
int maX, maY, miX, miY;
vector<int> listX[MAX_N], listY[MAX_N];
int n, m, k;
int64_t d = 0;
int nextX[4] = {0, 1, 0, -1};
int nextY[4] = {1, 0, -1, 0};
int flag = 1;
vector<int>::iterator it;
void Solve() {
  int upX = n, lowX = 1, upY = m, lowY = 1;
  int i = 1, j = 1, direct = 0;
  int64_t cnt = 1, turn = 1;
  while (1) {
    if (lowX > upX || lowY > upY) break;
    if (direct == 0) {
      int nY = upY;
      it = upper_bound(listX[i].begin(), listX[i].end(), j);
      if (it != listX[i].end()) nY = min(nY, (*it) - 1);
      if (nY == j && !turn) break;
      cnt += nY - j;
      j = nY;
      lowX = i + 1;
      turn = 0;
    } else if (direct == 1) {
      int nX = upX;
      it = upper_bound(listY[j].begin(), listY[j].end(), i);
      if (it != listY[j].end()) nX = min(nX, (*it) - 1);
      if (nX == i && !turn) break;
      cnt += nX - i;
      i = nX;
      upY = j - 1;
      turn = 0;
    } else if (direct == 2) {
      int nY = lowY;
      it = upper_bound(listX[i].begin(), listX[i].end(), j);
      if (it != listX[i].begin()) nY = max(nY, *(it - 1) + 1);
      if (nY == j && !turn) break;
      cnt += j - nY;
      j = nY;
      upX = i + 1;
      turn = 0;
    } else {
      int nX = lowX;
      it = upper_bound(listY[j].begin(), listY[j].end(), i);
      if (it != listY[j].begin()) nX = max(nX, *(it - 1) + 1);
      if (nX == i && !turn) break;
      cnt += i - nX;
      i = nX;
      lowY = j + 1;
      turn = 0;
    }
    direct = (direct + 1) % 4;
  }
  cerr << "cnt"
       << " = " << cnt << '\n';
  ;
  if (cnt + k == (int64_t)n * m)
    cout << "YES";
  else
    cout << "NO";
}
void Enter() {
  cin >> n >> m >> k;
  for (int i = (int)1; i <= (int)k; ++i) {
    int x, y;
    cin >> x >> y;
    listX[x].push_back(y);
    listY[y].push_back(x);
  }
  for (int i = (int)1; i <= (int)n; ++i) sort(listX[i].begin(), listX[i].end());
  for (int i = (int)1; i <= (int)m; ++i) sort(listY[i].begin(), listY[i].end());
}
int main() {
  Enter();
  Solve();
}
