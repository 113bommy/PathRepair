#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, tot, x, y;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  tot = n * n;
  map<long long, long long> mr;
  map<long long, long long> mc;
  vector<long long> v;
  long long sr = 0, sc = 0;
  while (m--) {
    cin >> x >> y;
    if (mr[x] == 1 && mc[y] == 1) {
    } else if (mr[x] == 1) {
      if (tot > 0) {
        tot = (tot - n) + 1 + (sr - 1);
      }
      sc++;
      mc[y]++;
    } else if (mc[y] == 1) {
      if (tot > 0) {
        tot = (tot - n) + 1 + (sc - 1);
      }
      sr++;
      mr[x]++;
    } else {
      if (tot > 0) {
        tot = ((tot - (n + n)) + 1) + sr + sc;
      }
      sr++;
      sc++;
      mr[x]++;
      mc[y]++;
    }
    v.push_back(tot);
  }
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
