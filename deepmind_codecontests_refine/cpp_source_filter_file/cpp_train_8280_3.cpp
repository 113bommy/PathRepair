#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  solve();
  return 0;
}
void solve() {
  int n;
  cin >> n;
  long long int c[2];
  cin >> c[0] >> c[1];
  if (c[0] > c[1]) swap(c[0], c[1]);
  if (c[0] == 0) {
    cout << n / 2 * c[1];
    return;
  }
  map<long long int, int> path;
  path[c[0]] += 1;
  path[c[1]] += 1;
  int sum = 2;
  while (sum < n) {
    long long int cost;
    int cnt;
    tie(cost, cnt) = *path.begin();
    void(0);
    ;
    void(0);
    ;
    path.erase(path.begin());
    int add = min(cnt, n - sum);
    path[cost + c[0]] += add;
    path[cost + c[1]] += add;
    if (add < cnt) {
      path[cost] = cnt - add;
    }
    sum += add;
  }
  cout << accumulate((path).begin(), (path).end(), 0LL,
                     [](long long int x, pair<long long int, int> p) {
                       return x + p.first * p.second;
                     });
}
