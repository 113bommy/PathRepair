#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, a, c = 0;
  cin >> n;
  map<int, int> x;
  x.clear();
  for (int i = 0; i < n; i++) {
    cin >> a;
    x[a]++;
    if (a && x[a] > 2)
      c = -2000;
    else if (a && x[a] == 2)
      c++;
  }
  cout << max(c, -1) << endl;
  return 0;
}
