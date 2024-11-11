#include <bits/stdc++.h>
using namespace std;
const int Z = 3 * (int)1e3 + 111;
const int N = 3 * (int)1e5 + 111;
const int INF = (int)1e9 + 111;
const int MOD = (int)1e9 + 7;
vector<int> a(N), b(N);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, tv1(-1 * INF), tv2(-1 * INF);
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  for (int i = 0; i < n - 1; i++) {
    if (a[i].first > tv1)
      tv1 = a[i].second;
    else if (a[i].first > tv2)
      tv2 = a[i].second;
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
