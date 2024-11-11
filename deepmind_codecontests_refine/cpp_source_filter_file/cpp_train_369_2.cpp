#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int cheese[MAX], mice[MAX];
int eated[MAX];
int ans;
void eat(int cheese_pos, int mice_pos) {
  if (eated[cheese_pos] == -1) {
    eated[cheese_pos] = mice_pos;
  } else {
    int old_dis = abs(mice[eated[cheese_pos]] - cheese[cheese_pos]);
    int new_dis = abs(cheese[cheese_pos] - mice[mice_pos]);
    if (new_dis < old_dis) {
      eated[cheese_pos] = mice_pos;
    } else if (new_dis == old_dis) {
      ans++;
    }
  }
}
void solve() {
  int n, m, y0, y1;
  scanf("%d %d %d %d", &n, &m, &y0, &y1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &mice[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &cheese[i]);
    eated[i] = -1;
  }
  ans = 0;
  int near_right = 0;
  for (int i = 0; i < n; ++i) {
    while (near_right < m && cheese[near_right] <= mice[i]) {
      near_right++;
    }
    if (near_right == m) {
      eat(near_right - 1, i);
    } else if (near_right == 0) {
      eat(near_right, i);
    } else {
      int left_distance = mice[i] - cheese[near_right - 1];
      int right_distance = cheese[near_right] - mice[i];
      if (right_distance < left_distance) {
        eat(near_right, i);
      } else if (right_distance > left_distance) {
        eat(near_right - 1, i);
      } else {
        if (eated[near_right - 1] == -1) {
          eat(near_right - 1, i);
        } else {
          int prev_dis =
              abs(mice[eated[near_right - 1]] - cheese[near_right - 1]);
          int new_dis = abs(mice[i] - cheese[near_right - 1]);
          if (new_dis <= prev_dis) {
            eat(near_right - 1, i);
          } else {
            eat(near_right, i);
          }
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (eated[i] != -1) {
      ans++;
    }
  }
  cout << n - ans;
}
int main() {
  solve();
  return 0;
}
