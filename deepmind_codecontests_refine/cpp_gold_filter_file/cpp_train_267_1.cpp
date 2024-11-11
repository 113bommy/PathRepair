#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  ;
  long long int c, vo, vl, a, l;
  cin >> c >> vo >> vl >> a >> l;
  long long int ctr = 0, day = 0;
  while (ctr < c) {
    ctr += min(vl, vo) - min(l, ctr);
    vo += a;
    day++;
  }
  cout << day << endl;
  return 0;
}
