#include <bits/stdc++.h>
using namespace std;
double maxi(double a, double b) {
  if (a > b) return a;
  return b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  double n, l;
  cin >> n >> l;
  vector<double> v;
  for (long long i = 0; i < n; i++) {
    double x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  if (v.size() == 1) {
    cout << setprecision(10);
    cout << maxi(v[0], l - v[0]);
    return 0;
  } else {
    long double ans = -1;
    long double cur_ans = -1;
    for (long long i = 1; i < v.size() - 1; i++) {
      cur_ans = maxi(v[i] - v[i - 1], v[i + 1] - v[i]) / 2.0;
      ans = maxi(ans, cur_ans);
    }
    ans = maxi(ans, maxi(v[0], l - v[v.size() - 1]));
    if (n == 2) ans = maxi(ans, v[1] - v[0]) / 2.0;
    cout << setprecision(10);
    cout << ans;
  }
  return 0;
}
