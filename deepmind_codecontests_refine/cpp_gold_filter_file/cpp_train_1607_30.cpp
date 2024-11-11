#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace std::chrono;
void fastaf(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve(void) {
  vector<pair<int64_t, int64_t>> cords(3);
  for (int i = 0; i < 3; i++) cin >> cords[i].first;
  for (int i = 0; i < 3; i++) cin >> cords[i].second;
  int64_t count = 0;
  for (auto x : cords) {
    if (x.first != x.second) count++;
  }
  if (count == 3)
    cout << "NO";
  else
    cout << "YES";
}
int main() {
  fastaf();
  solve();
  cout << "\n";
  return 0;
}
