#include <bits/stdc++.h>
using namespace std;
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  optimizeIO();
  int n;
  cin >> n;
  vector<vector<int> > v(4, vector<int>(2));
  for (typeof(4) i = 0; i < 4; i++) {
    int m1 = INT_MAX, m2 = INT_MAX;
    for (typeof(4) j = 0; j < 4; j++) {
      int x;
      cin >> x;
      if (j < 2)
        m1 = min(m1, x);
      else
        m2 = min(m2, x);
    }
    v[i][0] = m1;
    v[i][1] = m2;
  }
  int mi = 0;
  for (typeof(4) i = 0; i < 4; i++) {
    if (v[i][0] + v[i][1] < v[mi][0] + v[mi][1]) mi = i;
  }
  if (n < v[mi][0] + v[mi][1])
    cout << "-1\n";
  else {
    cout << mi + 1 << " " << v[mi][0] << " " << n - v[mi][0] << endl;
  }
  return 0;
}
