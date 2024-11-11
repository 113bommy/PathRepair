#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l = 0, r = 0;
  cin >> n;
  string w;
  cin >> w;
  for (int i = 0; i < 4; i++) {
    if (w[i] == 'L')
      l++;
    else
      r++;
  }
  cout << l + r + 1;
  return 0;
}
