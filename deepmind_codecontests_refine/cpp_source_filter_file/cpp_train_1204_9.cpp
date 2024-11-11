#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> lpf(N, 0), p;
void seive() {
  for (int i = 2; i <= N; i++) {
    if (lpf[i] == 0) {
      lpf[i] = i;
      p.push_back(i);
    }
    for (int j = 0; j < (int)p.size() && i * p[j] <= N && p[j] <= lpf[i]; j++)
      lpf[i * p[j]] = p[j];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  seive();
  map<int, int> m;
  auto update = [&](int a) {
    set<int> s;
    while (a != 1) {
      s.insert(lpf[a]);
      a /= lpf[a];
    }
    for (auto x : s) m[x]++;
  };
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    update(a);
  }
  int ans = 0;
  for (auto x : m) ans = max(ans, x.second);
  cout << ans << '\n';
  return 0;
}
