#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, j, k = 1, x;
  cin >> n;
  vector<int> col(n + 1);
  vector<int> vec[n + 1];
  for (i = 1; i < 1 + n; ++i) {
    cin >> x;
    vec[n - x].push_back(i);
  }
  for (i = 0; i < n + 1; ++i) {
    if (vec[i].size() == 0) continue;
    if (vec[i].size() % i != 0) {
      cout << "Impossible";
      return 0;
    }
    for (j = 0; j < vec[i].size(); ++j) {
      col[vec[i][j]] = k;
      ((j + 1) % i == 0 ? k += 1 : (1));
    }
    ++k;
  }
  cout << "Possible\n";
  for (i = 1; i < n + 1; ++i) cout << col[i] << " ";
}
