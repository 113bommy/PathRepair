#include <bits/stdc++.h>
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> Arr(4);
  for (long long int i = 0; i < 4; ++i) cin >> Arr[i];
  for (long long int i = 0; i < 3; ++i) {
    for (long long int j = 0; j < 3; ++j) {
      int dot = 0, dash = 0;
      Arr[i][j] == '.' ? dot++ : dash++;
      Arr[i][j + 1] == '.' ? dot++ : dash++;
      Arr[i + 1][j] == '.' ? dot++ : dash++;
      Arr[i + 1][j + 1] == '.' ? dot++ : dash++;
      if (dot == 3 || dash == 3) return cout << "YES" << '\n', 0;
    }
  }
  cout << "NO" << '\n';
}
