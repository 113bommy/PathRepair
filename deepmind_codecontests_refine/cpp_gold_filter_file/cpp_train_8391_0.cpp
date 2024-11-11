#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> q;
  for (int i = 0; i < m; i++) {
    int k, f;
    cin >> k >> f;
    q.insert(make_pair(k, f));
  }
  int ans = -1;
  for (int i = 1; i <= 100; i++) {
    bool f = true;
    for (auto it = q.begin(); it != q.end(); ++it) {
      if (((int)ceil((long double)it->first / (long double)i)) != it->second) {
        f = false;
        break;
      }
    }
    if (f && ans != -1 && ((int)ceil((long double)n / (long double)i)) != ans) {
      ans = -1;
      break;
    }
    if (f) {
      ans = ((int)ceil((long double)n / (long double)i));
    }
  }
  cout << ans << endl;
  return 0;
}
