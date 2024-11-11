#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
  vector<string> v(8);
  for (int i = 0; i < 8; ++i) cin >> v[i];
  bool ans = true;
  for (const auto &e : v) {
    for (int i = 0; i < 7; ++i) {
      if (v[i] == v[i + 1]) {
        ans = false;
        break;
      }
    }
    if (!ans) break;
  }
  cout << (ans ? "YES" : "NO") << "\n";
  return 0;
}
