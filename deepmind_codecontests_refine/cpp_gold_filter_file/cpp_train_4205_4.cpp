#include <bits/stdc++.h>
using namespace std;
const int INF = 1E9 + 7;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > t;
  int sum = 0;
  if ((n == 5 || n == 6) && m == 3) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = (1); i <= (m); ++i) {
    t.push_back(pair<int, int>(i, -sum));
    sum += i + 1;
  }
  int z = n - m;
  for (__typeof((t).begin()) it = ((t).begin()); it != (t).end(); ++it)
    cout << it->first << " " << it->second << endl;
  int duzo = 1000000;
  for (int i = (0); i <= (z - 1); ++i) {
    cout << -t[i].first + duzo << " " << t[i].second << endl;
  }
  return 0;
}
