#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
vector<vector<int>> v;
vector<bool> check;
vector<int> color;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n;
  v.resize(n + 1);
  check.resize(n + 1);
  color.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int c = 2;
  color[1] = 1;
  check[1] = true;
  queue<int> q;
  int baap[n + 1];
  int mx = 0;
  for (auto i : v[1]) {
    mx = max(mx, c);
    color[i] = c++;
    q.push(i);
    check[i] = true;
    baap[i] = 1;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    int d = 1;
    for (auto i : v[x]) {
      if (!check[i]) {
        if (color[baap[x]] == d || color[x] == d) {
          d++;
        }
        if (color[baap[x]] == d || color[x] == d) {
          d++;
        }
        mx = max(mx, d);
        color[i] = d;
        q.push(i);
        check[i] = true;
        baap[i] = x;
        d++;
      }
    }
  }
  cout << mx << "\n";
  for (int i = 1; i <= n; i++) cout << color[i] << " ";
  return 0;
}
