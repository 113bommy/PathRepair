#include <bits/stdc++.h>
using namespace std;
long double pd[101][101][101];
bool in[101][101][101];
int id[3];
int main() {
  vector<int> o(3, 0);
  cin >> o[0] >> o[1] >> o[2];
  pd[o[0]][o[1]][o[2]] = 1;
  queue<vector<int> > que;
  que.push(o);
  while (!que.empty()) {
    vector<int> q = que.front();
    que.pop();
    long double p = pd[q[0]][q[1]][q[2]];
    long double pairs = q[0] * q[1] + q[1] * q[2] + q[0] * q[2];
    for (int i = 0; i < 3; ++i) {
      if (q[i] && q[(i + 2) % 3]) {
        vector<int> nq = q;
        --nq[i];
        long double& ndp = pd[nq[0]][nq[1]][nq[2]];
        bool& nin = in[nq[0]][nq[1]][nq[2]];
        ndp += p * q[(i + 2) % 3] * q[i] / pairs;
        if (!nin) {
          nin = true;
          que.push(nq);
        }
      }
    }
  }
  for (int i = 0; i < 3; ++i) {
    long double ans = 0;
    id[0] = id[1] = id[2] = 0;
    for (int j = 1; j <= o[i]; ++j) {
      id[i] = j;
      ans += pd[id[0]][id[1]][id[2]];
    }
    cout << fixed << setprecision(20) << ans;
  }
  cout << endl;
  return 0;
}
