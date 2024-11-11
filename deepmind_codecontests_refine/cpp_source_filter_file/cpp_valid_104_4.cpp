#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MaxN = 500100;
int N;
vector<int> a;
bool pref[MaxN];
int breakpoint;
void check(vector<int> num, const vector<int> &ops) {
  for (auto mid : ops) {
    int r = num[mid - 1] ^ num[mid] ^ num[mid + 1];
    for (int z = mid - 1; z <= mid + 1; z++) num[z] = r;
  }
  for (int i = (1); i < (N + 1); i++) assert(num[i] == 0);
}
bool conditions() {
  if (pref[N] != 0) return false;
  for (int i = (1); i < (N + 1); i++) {
    if (i % 2 == 1 && pref[i] == 0) {
      breakpoint = i;
      return true;
    }
  }
  return false;
}
void solve() {
  if (!conditions()) {
    cout << "NO" << endl;
    return;
  };
  if (N % 2 == 1) breakpoint = N;
  assert(breakpoint % 2 == 1);
  vector<int> ops;
  for (int i = 2; i <= breakpoint - 1; i += 2) {
    ops.push_back(i);
  }
  for (int i = breakpoint - 3; i >= 2; i -= 2) {
    ops.push_back(i);
  }
  for (int i = breakpoint + 1; i <= N - 1; i += 2) {
    ops.push_back(i);
  }
  for (int i = N - 3; i >= breakpoint + 1; i -= 2) {
    ops.push_back(i);
  }
  cout << "YES" << endl;
  cout << ops.size() << endl;
  for (auto mid : ops) {
    cout << mid << " ";
  }
  cout << endl;
  check(a, ops);
}
void load() {
  breakpoint = -1;
  cin >> N;
  a.clear();
  a.resize(N + 1);
  a[0] = -100;
  for (int i = (0); i < (N); i++) cin >> a[i + 1];
  pref[0] = 0;
  for (int i = (0); i < (N); i++) pref[i + 1] = pref[i] ^ a[i + 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int tt = (0); tt < (T); tt++) {
    load();
    solve();
  }
  return 0;
}
