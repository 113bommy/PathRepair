#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  string s, d;
  cin >> n >> s >> d;
  vector<int> op(n - 1);
  for (int i = 0; i < n - 1; i++) {
    op[i] = d[i] - s[i];
    if (i != 0) op[i] -= op[i - 1];
  }
  if (s[n - 1] + op[n - 2] != d[n - 1]) {
    cout << "-1\n";
    return 0;
  }
  long long step = 0;
  set<int> up, down;
  auto can_up = [&s](int x) { return s[x] < '9'; };
  auto can_down = [&s](int x) { return (x > 0) ? (s[x] > '0') : (s[x] > '1'); };
  auto update = [&](int i) {
    if (auto x = op[i]; x > 0) {
      if (can_up(i) and can_up(i + 1)) up.insert(i);
    } else if (x < 0) {
      if (can_down(i) and can_down(i + 1)) down.insert(i);
    }
  };
  for (int i = 0; i < n - 1; i++) {
    auto x = op[i];
    step += (x > 0 ? x : -x);
    update(i);
  }
  cout << step << '\n';
  for (int i = 0; i < step and i < 100000; i++) {
    int j;
    if (not up.empty()) {
      j = *up.begin();
      up.erase(up.begin());
      assert(can_up(j) and can_up(j + 1));
      s[j]++, s[j + 1]++, op[j]--;
      cout << j + 1 << " 1\n";
      up.erase(j - 1);
      up.erase(j + 1);
    } else if (not down.empty()) {
      j = *down.begin();
      down.erase(down.begin());
      assert(can_down(j) and can_down(j + 1));
      s[j]--, s[j + 1]--, op[j]++;
      cout << j + 1 << " -1\n";
      down.erase(j - 1);
      down.erase(j + 1);
    } else {
      exit(-1);
    }
    update(j);
    if (j > 0) update(j - 1);
    if (j < n - 2) update(j + 1);
  }
}
