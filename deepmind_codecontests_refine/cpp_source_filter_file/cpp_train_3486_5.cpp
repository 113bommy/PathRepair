#include <bits/stdc++.h>
using namespace std;
int m, n;
char _m[55][55];
bool _findface(int x, int y) {
  char buf[6];
  for (int i = 0; i < 4; i++) {
    buf[i] = _m[x - i / 2][y - i % 2];
  }
  sort(buf, buf + 4);
  if (strcmp(buf, "acef") == 0)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> _m[i];
  }
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (_findface(i, j)) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
