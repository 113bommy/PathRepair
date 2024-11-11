#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = 1LL * INF * INF;
const int MAX = 1e6 + 7;
const double PI = acos(-1.);
const double EPS = 1e-7;
const int MAXN = 1 * 100007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      cin >> a[i][j];
    }
  }
  long long sq = (long long)(a[0][1] * a[0][2]) / a[1][2];
  long long num = sqrt(sq);
  while (num * num < sq) {
    ++num;
  }
  while (num * num > sq) {
    --num;
  }
  cout << num << " ";
  for (int i = 1; i < (n); ++i) {
    cout << a[0][i] / num << " ";
  }
  cout << "\n";
  return 0;
}
