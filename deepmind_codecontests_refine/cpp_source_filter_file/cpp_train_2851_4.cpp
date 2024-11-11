#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
const double error = 1e-7;
const double PI = acos(-1);
mt19937_64 rng(
    (unsigned int)chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9 + 5;
const long long int infl = 1e15;
const int nmax = 1e6 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<int> width[2];
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    width[x - 1].push_back(y);
  }
  width[0].push_back(0);
  width[1].push_back(0);
  sort(width[0].begin(), width[0].end());
  sort(width[1].begin(), width[1].end());
  for (int i = 0; i < 1; i++) {
    for (int j = 1; j < width[i].size(); j++) width[i][j] += width[i][j - 1];
  }
  int a = width[0].size();
  int b = width[1].size();
  int minsofar = inf;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      int x = i * 1 + j * 2;
      int y = width[0][a - 1 - i] + width[1][b - j - 1];
      if (y > x) continue;
      minsofar = min(minsofar, x);
    }
  }
  cout << minsofar;
  return 0;
}
