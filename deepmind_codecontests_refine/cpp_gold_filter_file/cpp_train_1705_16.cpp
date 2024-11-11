#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int mi = min(n, m);
  cout << mi + 1 << '\n';
  for (int i = 0; i <= mi; i++) cout << i << " " << mi - i << '\n';
  return 0;
}
