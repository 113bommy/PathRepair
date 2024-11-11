#include <bits/stdc++.h>
using namespace std;
int n, k, e;
pair<int, int> ori;
vector<pair<int, int> > ob;
vector<double> prob;
double calc() {
  vector<double> num(n + 1);
  num[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<double> num1(n + 1);
    for (int j = 0; j < i + 1; j++) {
      num1[j + 1] += num[j] * prob[i];
      num1[j] += num[j] * (1 - prob[i]);
    }
    num = num1;
  }
  double ans = 0;
  for (int i = 0; i < k; i++) ans += num[i];
  return ans;
}
double dist(pair<int, int> a, pair<int, int> b) {
  b.first -= a.first, b.second -= a.second;
  return b.first * b.first + b.second * b.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> e;
  ob.resize(n);
  prob.resize(n);
  cin >> ori.first >> ori.second;
  for (int i = 0; i < n; i++) cin >> ob[i].first >> ob[i].second;
  double low = 0, high = 4000000;
  while (high - low > 0.00000001) {
    double mid = (low + high) / 2;
    for (int i = 0; i < n; i++) {
      if (dist(ori, ob[i]) <= mid)
        prob[i] = 1;
      else
        prob[i] = exp(1 - dist(ori, ob[i]) / mid);
    }
    if (1000 * calc() >= e)
      low = mid;
    else
      high = mid;
  }
  cout << fixed << setprecision(9) << sqrt(low) << "\n";
}
