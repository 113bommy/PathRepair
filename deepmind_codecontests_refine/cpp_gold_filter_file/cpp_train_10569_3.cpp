#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
const int ops = 300;
const long double inf = 1e18;
bool lt(long double a, long double b) { return b - a > eps; }
bool eq(long double a, long double b) { return abs(a - b) <= eps; }
bool leq(long double a, long double b) { return lt(a, b) || eq(a, b); }
bool comp(pair<long double, long double>& a,
          pair<long double, long double>& b) {
  return lt(b.first / b.second, a.first / a.second);
}
struct data {
  long double a, p, q;
  bool operator<(const data& other) const { return lt(a, other.a); }
};
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<long double, long double> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i].second;
  }
  sort((v).begin(), (v).end(), comp);
  vector<data> d(n);
  vector<long double> sum(n);
  for (int i = 0; i < n; ++i) {
    if (i) {
      sum[i] = sum[i - 1];
    }
    sum[i] += v[i].second;
  }
  vector<int> group(n, -1);
  int g = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (v[i].first * v[i + 1].second == v[i + 1].first * v[i].second) {
      group[i] = group[i + 1] = g;
    } else {
      group[i] = g;
      group[i + 1] = g + 1;
      ++g;
    }
  }
  vector<int> finish(g + 1);
  for (int i = 0; i < n; ++i) {
    finish[group[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    d[i].a = v[i].first;
    long double x = 0;
    if (group[i]) {
      x = sum[finish[group[i] - 1]];
    }
    x += v[i].second;
    d[i].p = v[i].first * sum[finish[group[i]]];
    d[i].q = v[i].first * x;
  }
  sort((d).begin(), (d).end());
  long double lf = 0.0, rg = 1.0;
  for (int step = 0; step < ops; ++step) {
    long double c = (lf + rg) / 2;
    c /= sum[n - 1];
    long double maxim1 = -inf, maxim2 = -inf;
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (j && d[j].a != d[j - 1].a) {
        maxim1 = maxim2;
      }
      if (leq(d[j].a - c * d[j].p, maxim1)) {
        ok = false;
        break;
      }
      if (lt(maxim2, d[j].a - c * d[j].q)) {
        maxim2 = d[j].a - c * d[j].q;
      }
    }
    if (ok) {
      lf = c * sum[n - 1];
    } else {
      rg = c * sum[n - 1];
    }
  }
  cout << fixed;
  cout.precision(10);
  cout << lf << "\n";
}
