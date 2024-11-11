#include <bits/stdc++.h>
using namespace std;
enum { EMPTY, HOUSE, SHOP };
int n, t;
int a[500010];
int house_num, shop_num, last_house;
bool check(int k) {
  if (k < house_num - shop_num) return false;
  vector<pair<int, int> > turn;
  int time = 0, lack = 0, last;
  for (int i = 0; i < (int)(n); ++i) {
    ++time;
    if (a[i] == HOUSE) {
      if (k == 0) lack = i;
      --k;
    } else if (a[i] == SHOP) {
      if (k == -1) {
        turn.push_back(pair<int, int>(lack, i));
        time += 2 * (i - lack);
      }
      ++k;
    }
  }
  if (!turn.empty() && last_house < turn.back().second) {
    last = turn.back().first;
    turn.pop_back();
  } else {
    last = last_house;
  }
  time -= n - last - 1;
  while (!turn.empty()) {
    pair<int, int> &p = turn.back();
    if (last - 3 * p.first + 2 * p.second < 2 * (last - p.first)) break;
    time -= last - 3 * p.first + 2 * p.second;
    time += 2 * (last - p.first);
    last = p.first;
    turn.pop_back();
  }
  return time <= t;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  char c;
  cin >> n >> t;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> c;
    switch (c) {
      case '.':
        a[i] = EMPTY;
        break;
      case 'H':
        a[i] = HOUSE;
        ++house_num;
        last_house = i;
        break;
      case 'S':
        a[i] = SHOP;
        ++shop_num;
        break;
    }
  }
  if (t < last_house) {
    cout << -1 << endl;
    return 0;
  }
  int lb = -1, ub = 2 * n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    (check(mid) ? ub : lb) = mid;
  }
  cout << ub << endl;
}
