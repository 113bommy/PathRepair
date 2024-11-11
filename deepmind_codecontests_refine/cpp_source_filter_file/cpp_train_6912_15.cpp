#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string x;
  cin >> x;
  int ans = 0;
  for (int i = 4; i < int((x).size()); i += n) {
    ans += (x[i - 1] == x[i - 2] && x[i - 2] == x[i - 3]);
  }
  cout << ans << endl;
}
