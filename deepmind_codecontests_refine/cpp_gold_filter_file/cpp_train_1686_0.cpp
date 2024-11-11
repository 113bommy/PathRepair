#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  vector<vector<long long int> > grid(n, vector<long long int>(n, 0));
  long long int value = 1;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    for (__typeof(n) j = (0) - ((0) > (n)); j != (n) - ((0) > (n));
         j += 1 - 2 * ((0) > (n))) {
      grid[i][j] = value;
      value++;
    }
  }
  vector<vector<long long int> > groups(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (i % 2 == 0) {
      for (__typeof(n) j = (0) - ((0) > (n)); j != (n) - ((0) > (n));
           j += 1 - 2 * ((0) > (n))) {
        groups[j].push_back(grid[i][j]);
      }
    } else {
      long long int t = 0;
      for (__typeof(0) j = (n) - ((n) > (0)); j != (0) - ((n) > (0));
           j += 1 - 2 * ((n) > (0))) {
        groups[t].push_back(grid[i][j]);
        t++;
      }
    }
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    for (__typeof(n) j = (0) - ((0) > (n)); j != (n) - ((0) > (n));
         j += 1 - 2 * ((0) > (n))) {
      cout << groups[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
