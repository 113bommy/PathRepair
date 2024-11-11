#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const long long LINF = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long N = 1000000;
void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  vector<int> q(n);
  vector<double> dq(n);
  double cur = 1;
  for (int i = 0; i < n; ++i) {
    q[i] = 100 - p[i];
    dq[i] = 0.01 * q[i];
    cur *= (1.0 - dq[i]);
  }
  vector<double> curq = dq;
  double res = n + 1 - cur;
  vector<int> k(n, 1);
  priority_queue<pair<double, int> > qu;
  for (int i = 0; i < n; ++i) {
    qu.push(make_pair(0.01 * p[i] * curq[i] / (1 - curq[i]), i));
  }
  for (int i = 0; i < 1000000; ++i) {
    pair<double, int> ver = qu.top();
    qu.pop();
    int ind = ver.second;
    cur *= (ver.first + 1);
    res += 1 - cur;
    ++k[ind];
    curq[ind] *= dq[ind];
    qu.push(make_pair(0.01 * p[ind] * curq[ind] / (1 - curq[ind]), ind));
  }
  printf("%0.12f\n", res);
}
int main() {
  solve();
  return 0;
}
