#include <bits/stdc++.h>
using namespace std;
bool check(int n, int m, int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
const long long MAX = 1000000007, MAXL = 1LL << 60, dx[4] = {-1, 0, 1, 0},
                dy[4] = {0, 1, 0, -1};
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = (int)(0); i < (int)(n); i++) {
    int c = 0, x;
    for (int j = (int)(0); j < (int)(n); j++) {
      cin >> x;
      if (i == j) continue;
      if (!x || x == 2) c++;
    }
    if (c == n - 1) v.push_back(i + 1);
  }
  cout << (v.size()) << endl;
  if (v.size()) {
    for (int i = (int)(0); i < (int)(v.size()); i++) {
      if (i) cout << " ";
      cout << v[i];
    }
    cout << endl;
  }
  return 0;
}
