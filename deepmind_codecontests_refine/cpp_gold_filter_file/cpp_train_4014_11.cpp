#include <bits/stdc++.h>
using namespace std;
const int M = 400 + 10;
int a[M][M];
int out[M][M];
char result[M][M];
int v[M][2];
queue<pair<int, int> > Queue;
int main() {
  int X, Y, n, d;
  cin >> X >> Y >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1];
  }
  for (int x = 0; x <= 400; x++) {
    for (int y = 0; y <= 400; y++) {
      if ((x - 200) * (x - 200) + (y - 200) * (y - 200) <= d * d) {
        for (int i = 0; i < n; i++) {
          int x1 = x + v[i][0] - 200;
          int y1 = y + v[i][1] - 200;
          if (x1 * x1 + y1 * y1 <= d * d) {
            out[x][y]++;
          }
        }
        if (out[x][y] == 0) {
          Queue.push(make_pair(x, y));
        }
        result[x][y] = 'L';
      }
    }
  }
  while (Queue.size() > 0) {
    int x = Queue.front().first;
    int y = Queue.front().second;
    for (int i = 0; i < n; i++) {
      int x1 = x - v[i][0];
      int y1 = y - v[i][1];
      if ((x1 - 200) * (x1 - 200) + (y1 - 200) * (y1 - 200) <= d * d) {
        out[x1][y1]--;
        if (out[x1][y1] == 0) {
          Queue.push(make_pair(x1, y1));
        }
        if (result[x][y] == 'L') {
          result[x1][y1] = 'W';
        }
      }
    }
    Queue.pop();
  }
  if (result[X + 200][Y + 200] == 'W') {
    cout << "Anton" << endl;
  } else {
    cout << "Dasha" << endl;
  }
  return 0;
}
