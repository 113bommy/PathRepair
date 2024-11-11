#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  bool bulbs[128] = {false};
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      cin >> y;
      bulbs[y] = true;
    }
  }
  printf("%s\n", all_of(bulbs + 1, bulbs + m + 1, [](bool a) { return a; })
                     ? "YES"
                     : "NO");
  return 0;
}
