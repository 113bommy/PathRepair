#include <bits/stdc++.h>
using namespace std;
const int mn = 500005;
const int INF = 1e9 + 7;
pair<int, int> a[mn];
int dist(pair<int, int> q, pair<int, int> w) {
  int h = w.first - q.first;
  if (w.second - q.second < 0) {
    w.second += 60;
    h--;
  }
  return h * 60 + w.second - q.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int h = 0, m = 0;
    h += (s[0] - '0') * 10 + s[1] - '0';
    m += (s[3] - '0') * 10 + s[4] - '0';
    a[i].first = h;
    a[i].second = m;
  }
  if (n == 1) {
    cout << "23:59";
    return 0;
  }
  sort(a, a + n);
  int ans = 0, ansh = 0, ansm = 0;
  for (int i = 1; i < n; i++) {
    if (dist(a[i - 1], a[i]) - 1 > ans) {
      ans = dist(a[i - 1], a[i]) - 1;
      ansh = ans / 60;
      ansm = ans % 60;
    }
  }
  if (24 * 50 - dist(a[0], a[n - 1]) - 1 > ans) {
    ans = 24 * 60 - dist(a[0], a[n - 1]) - 1;
    ansh = ans / 60;
    ansm = ans % 60;
  }
  if (ansh / 10 >= 1) {
    cout << ansh;
  } else {
    cout << '0' << ansh;
  }
  cout << ':';
  if (ansm / 10 >= 1) {
    cout << ansm;
  } else {
    cout << '0' << ansm;
  }
  return 0;
}
