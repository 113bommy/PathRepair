#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979323846;
long long mod = 1000000000 + 7;
const int N = 1e5 + 5;
vector<bool> prime(N, true);
bool Rev(long long a, long long b) { return (a > b); }
void solve() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double time = d / v;
  long long flag = 0, f = 0;
  double sum = 0;
  while (time >= sum) {
    if (!f) {
      sum += g;
      f = 1;
      if (time < sum) {
        flag = 1;
        break;
      }
    } else {
      sum += r;
      f = 0;
    }
  }
  if (flag) {
    printf("%.8f", l / v);
  } else {
    printf("%.8f", sum + (l - d) / v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  solve();
}
