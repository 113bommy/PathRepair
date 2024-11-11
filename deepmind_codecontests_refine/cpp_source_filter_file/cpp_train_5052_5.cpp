#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long MOD = 1e9 + 9;
bool isPrime(long long x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
double dist(double a, double b, double c, double d) {
  return sqrt((c - a) * (c - a) + (d - b) * (d - b));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  srand(time(0));
  int n, b;
  cin >> n >> b;
  vector<pair<long long, long long>> v(n), ans(n);
  for (int i = 0; i < n; i++) {
    int t, d;
    cin >> t >> d;
    v[i] = {t, d};
  }
  int fin = v[0].first + v[0].second;
  deque<long long> q;
  cout << fin << " ";
  q.push_back(fin);
  for (int i = 1; i < n; i++) {
    while (!q.empty()) {
      if (q[0] <= v[i].first) {
        q.pop_front();
      } else {
        break;
      }
    }
    if (q.size() - 1 == b) {
      cout << "-1 ";
      continue;
    }
    if (v[i].first <= fin) {
      fin += v[i].second;
    } else {
      fin = v[i].first + v[i].second;
    }
    q.push_back(fin);
    cout << fin << " ";
  }
  return 0;
}
