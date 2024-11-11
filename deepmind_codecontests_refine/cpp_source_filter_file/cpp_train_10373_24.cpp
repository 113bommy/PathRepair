#include <bits/stdc++.h>
using namespace std;
string t[100];
int n, m;
int64_t C[100][100];
int64_t Bell[100];
const int64_t M = 1000000007;
void prepare_bell() {
  for (int i = 0; i <= 50; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
  }
  Bell[0] = Bell[1] = 1;
  for (int i = 2; i <= 50; i++) {
    int64_t sum = 0;
    for (int j = 0; j <= i - 1; j++) sum = (sum + C[i - 1][j] * Bell[j]) % M;
    Bell[i] = sum;
  }
}
bool equiv(int x, int y) {
  for (int i = 0; i < n; i++) {
    if (t[i][x] != t[i][y]) return false;
  }
  return true;
}
int main() {
  prepare_bell();
  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  vector<bool> used(m, false);
  int64_t ans = 1;
  for (int i = 0; i < m; i++) {
    if (used[i]) continue;
    used[i] = true;
    vector<int> f;
    f.push_back(i);
    for (int j = i + 1; j < m; j++) {
      if (equiv(i, j)) {
        used[j] = true;
        f.push_back(j);
      }
    }
    ans = (ans * Bell[f.size()]) % M;
  }
  cout << ans << "\n";
  return 0;
}
