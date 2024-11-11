#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0, n, m;
  cin >> n >> m;
  for (int i = 1; i <= min(n, m); i++) {
    cnt += ((i + max(n, m)) / 5 - (i) / 5);
  }
  cout << cnt << endl;
  return 0;
}
