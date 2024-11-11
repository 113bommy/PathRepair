#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
vector<int> vec[maxn];
int n, m, k, ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec[x - 1].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int ptr = 0;
    for (int j = 0; j < ((int)(vec[i]).size()); j++) {
      int init = vec[i][j];
      while (ptr < ((int)(vec[i]).size()) and
             vec[i][ptr] - init - (ptr - i) <= k)
        ptr++;
      ((ans) = max((ans), (ptr - j)));
    }
  }
  cout << ans << endl;
  return 0;
}
