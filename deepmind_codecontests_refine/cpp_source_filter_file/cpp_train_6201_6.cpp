#include <bits/stdc++.h>
using namespace std;
long long diag1[200001];
long long diag2[200001];
int diag1_entry[200001];
int diag2_entry[200001];
const long long alot = 1000000000000000000LL;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int current_x = 0;
  int current_y = 0;
  int dx = 1;
  int dy = 1;
  int t = 0;
  for (int i = 0; i < 200001; ++i) {
    diag1[i] = -1;
    diag1_entry[i] = -1;
    diag2[i] = -1;
    diag2_entry[i] = -1;
  }
  diag2[100000] = 0;
  diag2_entry[100000] = 0;
  while (true) {
    if (dx == 1 && dy == 1) {
      int diag = current_x - current_y;
      int y = n - diag;
      if (y == m) break;
      if (y < m) {
        t += n - current_x;
        current_x = n;
        current_y = y;
        dx = -1;
      } else {
        t += m - current_y;
        current_y = m;
        current_x = m + diag;
        dy = -1;
      }
      int new_diag = current_x + current_y;
      diag1[new_diag] = t;
      diag1_entry[new_diag] = current_x;
    } else if (dx == -1 && dy == -1) {
      int diag = current_x - current_y;
      int y = -diag;
      if (y == 0) break;
      if (y > 0) {
        t += current_x;
        current_x = 0;
        current_y = y;
        dx = 1;
      } else {
        t += current_y;
        current_y = 0;
        current_x = diag;
        dy = 1;
      }
      int new_diag = current_x + current_y;
      diag1[new_diag] = t;
      diag1_entry[new_diag] = current_x;
    } else if (dx == 1 && dy == -1) {
      int diag = current_x + current_y;
      int y = diag - n;
      if (y == 0) break;
      if (y > 0) {
        t += n - current_x;
        current_x = n;
        current_y = y;
        dx = -1;
      } else {
        t += current_y;
        current_y = 0;
        current_x = diag;
        dy = 1;
      }
      int new_diag = 100000 + current_x - current_y;
      diag2[new_diag] = t;
      diag2_entry[new_diag] = current_x;
    } else if (dx == -1 && dy == 1) {
      int diag = current_x + current_y;
      int y = diag;
      if (y == m) break;
      if (y < m) {
        t += current_x;
        current_x = 0;
        current_y = y;
        dx = 1;
      } else {
        t += m - current_y;
        current_y = m;
        current_x = diag - m;
        dy = -1;
      }
      int new_diag = 100000 + current_x - current_y;
      diag2[new_diag] = t;
      diag2_entry[new_diag] = current_x;
    }
  }
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    long long ans = alot;
    if (diag1[x + y] != -1) {
      long long t = diag1[x + y] + abs(x - diag1_entry[x + y]);
      if (t < ans) ans = t;
    }
    int diag_num = x - y + 100000;
    if (diag2[diag_num] != -1) {
      long long t = diag2[diag_num] + abs(x - diag2_entry[diag_num]);
      if (t < ans) ans = t;
    }
    if (ans == alot) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
