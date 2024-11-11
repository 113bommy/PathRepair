#include <bits/stdc++.h>
using namespace std;
int n, m, s, f, t;
int nextTime(int curTime, int floor) {
  int postCycle = curTime % (2 * m - 2);
  int preCycle = curTime - postCycle;
  int t1 = floor - 1, t2 = 2 * m - floor - 1;
  if (postCycle <= t1)
    return preCycle + t1;
  else if (postCycle <= t2)
    return preCycle + t2;
  else
    return preCycle + t1 + 2 * m - 2;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s >> f >> t;
    if (s != f) {
      t = nextTime(t, s);
      t = nextTime(t, f);
    }
    cout << t << endl;
  }
}
