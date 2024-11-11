#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int p[n], t[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> t[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if ((p[j] > p[i]) || (p[j] == p[i] && t[j] <= t[i])) {
        swap(p[i], p[j]);
        swap(t[i], t[j]);
      }
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) m[pair<int, int>(p[i], t[i])]++;
  cout << m[pair<int, int>(p[k - 1], t[k - 1])] << '\n';
  return 0;
}
