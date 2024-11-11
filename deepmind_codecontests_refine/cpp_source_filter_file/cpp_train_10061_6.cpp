#include <bits/stdc++.h>
using namespace std;
const long long nInf = -1000000000;
const long long pInf = 1000000000;
const long long mod = 1000000007;
const int MAXN = 1e6 + 10;
int n;
void read_data() { cin >> n; }
int prev1[MAXN];
void solve() {
  fill(prev1, prev1 + MAXN, -1);
  for (int i = 2; i < MAXN; i++) {
    if (prev1[i] == -1) {
      prev1[i] = i;
      for (int j = 2; i * j <= MAXN; j++) {
        prev1[i * j] = i;
      }
    }
  }
  vector<int> poss;
  for (int i = 0; i < prev1[n]; i++) {
    poss.push_back(n - i);
  }
  int res = pInf;
  for (int i = 0; i < (int)poss.size(); i++) {
    if (res > poss[i] - prev1[poss[i]] + 1 && prev1[poss[i]] != poss[i]) {
      res = poss[i] - prev1[poss[i]] + 1;
    }
  }
  cout << res;
}
int main() {
  read_data();
  solve();
  return 0;
}
