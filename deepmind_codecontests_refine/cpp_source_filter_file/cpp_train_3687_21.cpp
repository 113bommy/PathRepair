#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int M = INF;
const double RRR = 180.0 / PI;
vector<vector<pair<int, int> > > g;
vector<int> used;
vector<int> p;
int main() {
  double TIME_START = clock();
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> mas(k);
  int a;
  for (int i = 0; i < k; i++) {
    cin >> a;
    mas[i % k] += a;
  }
  int ans = 0;
  int tt = mas[0];
  for (int i = 0; i < k; i++) {
    if (mas[i] < tt) {
      tt = mas[i];
      ans = i;
    }
  }
  cout << ans + 1;
  return 0;
}
