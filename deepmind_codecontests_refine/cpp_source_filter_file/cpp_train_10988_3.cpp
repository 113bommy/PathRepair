#include <bits/stdc++.h>
using namespace std;
struct locked_door {
  int x1, y1;
  int x2, y2;
};
vector<int> decompos_res;
vector<locked_door> ans;
int n;
void decompos_t_with_6_base(long long int t) {
  while (t) {
    decompos_res.push_back(t % 6);
    t = t / 6;
  }
}
bool is_valid(int num) { return (num > 0) && (num <= 2 * n + 2); }
void add_locked_door(int x1, int y1, int x2, int y2) {
  if (!is_valid(x1) || !is_valid(y1) || !is_valid(x2) || !is_valid(y2)) return;
  ans.push_back({x1, y1, x2, y2});
}
void build_ans(int x, int y, int digit) {
  add_locked_door(x, y + 2, x + 1, y + 2);
  add_locked_door(x - 1, y + 4, x, y + 4);
  add_locked_door(x + 1, y + 3, x + 1, y + 4);
  add_locked_door(x + 1, y + 5, x + 2, y + 5);
  add_locked_door(x + 2, y + 3, x + 2, y + 4);
  add_locked_door(x + 4, y - 1, x + 4, y);
  add_locked_door(x + 3, y + 1, x + 4, y + 1);
  add_locked_door(x + 3, y + 2, x + 4, y + 2);
  add_locked_door(x + 5, y + 1, x + 4, y + 2);
  if (digit < 3) add_locked_door(x + 2, y, x + 2, y + 1);
  if (digit % 3 < 2) add_locked_door(x + 3, y, x + 3, y + 1);
  if (digit % 3 == 0) add_locked_door(x, y + 3, x + 1, y + 3);
}
int main() {
  long long int t;
  cin >> t;
  decompos_t_with_6_base(t);
  reverse(decompos_res.begin(), decompos_res.end());
  n = (int)decompos_res.size();
  add_locked_door(1, 2, 2, 2);
  add_locked_door(2, 1, 2, 2);
  int cur_x = 1, cur_y = 1;
  for (int i = 0; i < n; i++) {
    build_ans(cur_x, cur_y, decompos_res[i]);
    cur_x += 2;
    cur_y += 2;
  }
  cout << cur_x + 1 << " " << cur_y + 1 << endl;
  cout << ans.size() << endl;
  for (auto door : ans) {
    cout << door.x1 << " " << door.y1 << " " << door.x2 << " " << door.y2
         << endl;
  }
  return 0;
}
