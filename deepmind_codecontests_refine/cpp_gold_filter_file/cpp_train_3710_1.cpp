#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int h, a, c, j, k, l = 0;
  cin >> h >> a >> c >> j >> k;
  bool ans[10000] = {false};
  while (j > 0) {
    if (h <= k && j > a) {
      ans[l] = true;
      h += (c - k);
    } else {
      j -= a;
      h -= k;
    }
    l++;
  }
  cout << l << "\n";
  for (int i = 0; i < l; ++i) {
    if (ans[i] == true) {
      cout << "HEAL\n";
    } else {
      cout << "STRIKE\n";
    }
  }
  return 0;
}
