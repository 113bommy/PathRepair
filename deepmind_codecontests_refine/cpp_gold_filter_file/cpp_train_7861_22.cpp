#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12;
const long double PI = acos(-1);
const int MAXN = 100005;
int N;
long double A, X[MAXN], Y[MAXN];
bool check(long double m) {
  long double u = m / 2;
  long double v = sqrt(A * A - u * u);
  vector<pair<long double, long double>> ev;
  for (int i = 0; i < N; i++) {
    long double x = 1, y = Y[i] / v, alpha;
    if (X[i] != 0) {
      x *= u / X[i], y *= u / X[i];
      long double r = sqrt(x * x + y * y);
      if (r < 1) continue;
      alpha = acos(1 / r);
    } else {
      alpha = PI / 2;
    }
    long double base = atan2(y, x) - alpha;
    if (base < 0) base += 2 * PI;
    ev.push_back({base, base + 2 * alpha});
  }
  priority_queue<long double, vector<long double>, greater<long double>> pq;
  sort(ev.begin(), ev.end());
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < ev.size(); j++) {
      while (pq.size() && pq.top() < ev[j].first) pq.pop();
      if (pq.size() && pq.top() < ev[j].second) return 1;
      pq.push(ev[j].second);
      ev[j].first += 2 * PI;
      ev[j].second += 2 * PI;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> N >> A;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  long double lo = 0, hi = 2 * A;
  while (hi - lo > EPS) {
    long double mid = (lo + hi) / 2;
    (check(mid) ? hi : lo) = mid;
  }
  cout << fixed << setprecision(10);
  cout << (lo + hi) / 2 << endl;
}
