#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 30; i >= 0; --i) {
    int j = (1 << i) & n;
    if (j != 0) cout << (i + 1) << " ";
  }
  return 0;
}
