#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans[17] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
  int a;
  while (cin >> a) {
    cout << ans[a] << endl;
  }
  return 0;
}
