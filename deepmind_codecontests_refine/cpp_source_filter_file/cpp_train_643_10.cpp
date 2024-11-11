#include <bits/stdc++.h>
#pragma disable(warning : 4996)
using namespace std;
using ll = long long;
enum { MAX = 200005 };
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int cnt[8];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, sx, sy;
  cin >> n >> sx >> sy;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == sx && y > sy) {
      cnt[0]++;
    } else if (x > sx && y > sy) {
      cnt[0]++;
      cnt[1]++;
      cnt[2]++;
    }
    if (x > sx && y == sy) {
      cnt[2]++;
    }
    if (x > sx && y < sy) {
      cnt[2]++;
      cnt[3]++;
      cnt[4]++;
    }
    if (x == sx && y < sy) {
      cnt[4]++;
    }
    if (x < sx && y < sy) {
      cnt[4]++;
      cnt[5]++;
      cnt[6]++;
    }
    if (x < sx && y == sy) {
      cnt[6]++;
    }
    if (x > sx && y < sy) {
      cnt[6]++;
      cnt[7]++;
      cnt[0]++;
    }
  }
  int idx = 0;
  for (int i = 0; i < 8; i++) {
    if (cnt[idx] < cnt[i]) idx = i;
  }
  cout << cnt[idx] << endl;
  cout << sx + dx[idx] << " " << sy + dy[idx] << endl;
  return 0;
}
