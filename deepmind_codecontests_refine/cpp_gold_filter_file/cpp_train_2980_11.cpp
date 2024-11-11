#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 63 - 1;
long long k, a, b;
pair<long long, long long> state[9];
long long cyc[9];
long long vis[9], cnt;
long long al[9], bo[9];
int main() {
  cin >> k >> a >> b;
  a--;
  b--;
  int ss = a * 3 + b;
  for (int i = 0; i < 9; i++) {
    cin >> al[i];
    al[i]--;
  }
  for (int i = 0; i < 9; i++) {
    cin >> bo[i];
    bo[i]--;
  }
  long long step = 1, awin = 0, bwin = 0;
  bool stop = false;
  while (!stop) {
    awin += (((ss + 1) % 3) == ss / 3);
    bwin += (((ss / 3 + 1) % 3) == ss % 3);
    if (step == k) {
      return cout << awin << " " << bwin, 0;
    }
    if (vis[ss] == 0) state[ss] = {awin, bwin}, cyc[ss] = step;
    if (vis[ss] == 1)
      state[ss] = {awin - state[ss].first, bwin - state[ss].second},
      cyc[ss] = step - cyc[ss];
    vis[ss]++;
    if (vis[ss] == 2) break;
    ss = al[ss] * 3 + bo[ss];
    step++;
  }
  long long num = (k - step) / cyc[ss];
  awin += num * state[ss].first;
  bwin += num * state[ss].second;
  step += num * cyc[ss];
  while (step < k) {
    ss = al[ss] * 3 + bo[ss];
    step++;
    awin += (((ss + 1) % 3) == ss / 3);
    bwin += (((ss / 3 + 1) % 3) == ss % 3);
  }
  return cout << awin << " " << bwin, 0;
  return 0;
}
