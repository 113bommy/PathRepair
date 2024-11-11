#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double EPS = 1e-6;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const int maxV = 1000000;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k + 1, 0);
  vector<int> timeR(n, 0);
  vector<int> timeC(m, 0);
  int type, idx, color;
  for (int i = 1; i <= k; i++) {
    cin >> type >> idx >> color;
    if (type == 1) {
      timeR[idx] = i;
    } else {
      timeC[idx] = i;
    }
    a[i] = color;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[max(timeR[i], timeC[j])] << " ";
    }
    cout << endl;
  }
}
