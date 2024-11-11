#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
int K, n;
double prob;
double inv(vector<int> in) {
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (in[i] > in[j]) ans = ans + 1.0;
  return ans;
}
double solve(int done, vector<int> curr) {
  if (done == K) return inv(curr);
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      vector<int> tp = curr;
      vector<int>::iterator st = tp.begin(), ed = tp.begin();
      for (int k = 0; k < i; k++) st++;
      for (int k = 0; k <= j; k++) ed++;
      reverse(st, ed);
      ans += solve(done + 1, tp);
    }
  return ans * prob;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> K;
  vector<int> in;
  in.resize(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  if (n == 1) {
    cout << "0.00000000000000000000000000000000000000" << endl;
    return 0;
  }
  prob = (n * (n - 1));
  prob = 1.00000000 / prob;
  cout << fixed << setprecision(15) << solve(0, in) << endl;
  return 0;
}
