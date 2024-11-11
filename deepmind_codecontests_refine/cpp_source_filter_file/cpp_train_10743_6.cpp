#include <bits/stdc++.h>
using namespace std;
mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
T randInt(T min, T max) {
  uniform_int_distribution<T> dist(min, max);
  return dist(gen);
}
template <typename T>
T randDouble(T min, T max) {
  uniform_real_distribution<T> dist(min, max);
  return dist(gen);
}
double workTime() { return double(clock()) / CLOCKS_PER_SEC; }
void myReturn(int code = 0) { exit(code); }
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int CASE;
  cin >> CASE;
  while (CASE--) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<pair<int, int> > a;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      sum += t;
      a.push_back({t, i});
    }
    if (m < n) {
      cout << -1 << endl;
    } else {
      sum <<= 1;
      sort(a.begin(), a.end());
      cout << sum + (a[0].first + a[1].first) * (m - n) << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << ' ' << (i == n ? 1 : i + 1) << endl;
      }
      for (int i = n; i < m; i++) {
        cout << a[0].second + 1 << ' ' << a[1].second + 1 << endl;
      }
    }
  }
  myReturn();
}
