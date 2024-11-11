#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
void build() {}
long long int modexp(long long int base, long long int exponent,
                     long long int modulus) {
  if (modulus == 1) return 0;
  long long int result = 1;
  base = base % modulus;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long int dis(int a, int b, int x, int y) {
  return pow(abs(a - x), 2) + pow(abs(b - y), 2);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  build();
  int n;
  cin >> n;
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  string s[n];
  r1--;
  c1--;
  r2--;
  c2--;
  for (int i = 0; i < n; i++) cin >> s[i];
  queue<pair<int, int>> q;
  q.push(make_pair(r1, c1));
  bool visited[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) visited[i][j] = 0;
  }
  visited[r1][c1] = 1;
  vector<pair<int, int>> st;
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();
    if (x.first + 1 < n && !visited[x.first + 1][x.second] &&
        s[x.first + 1][x.second] == '0') {
      q.push(make_pair(x.first + 1, x.second));
      visited[x.first + 1][x.second] = 1;
    }
    if (x.first - 1 >= 0 && !visited[x.first - 1][x.second] &&
        s[x.first - 1][x.second] == '0') {
      visited[x.first - 1][x.second] = 1;
      q.push(make_pair(x.first - 1, x.second));
    }
    if (x.second + 1 < n && !visited[x.first][x.second + 1] &&
        s[x.first][x.second + 1] == '0') {
      visited[x.first][x.second + 1] = 1;
      q.push(make_pair(x.first, x.second + 1));
    }
    if (x.second - 1 >= 0 && !visited[x.first][x.second - 1] &&
        s[x.first][x.second - 1] == '0') {
      visited[x.first][x.second - 1] = 1;
      q.push(make_pair(x.first, x.second - 1));
    }
    st.push_back(make_pair(x.first, x.second));
  }
  queue<pair<int, int>> q1;
  q1.push(make_pair(r2, c2));
  bool visited1[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) visited1[i][j] = 0;
  }
  visited1[r2][c2] = 1;
  vector<pair<int, int>> en;
  while (!q1.empty()) {
    pair<int, int> x = q1.front();
    q1.pop();
    if (x.first + 1 < n && !visited1[x.first + 1][x.second] &&
        s[x.first + 1][x.second] == '0') {
      q1.push(make_pair(x.first + 1, x.second));
      visited1[x.first + 1][x.second] = 1;
    }
    if (x.first - 1 >= 0 && !visited1[x.first - 1][x.second] &&
        s[x.first - 1][x.second] == '0') {
      visited1[x.first - 1][x.second] = 1;
      q1.push(make_pair(x.first - 1, x.second));
    }
    if (x.second + 1 < n && !visited1[x.first][x.second + 1] &&
        s[x.first][x.second + 1] == '0') {
      visited1[x.first][x.second + 1] = 1;
      q1.push(make_pair(x.first, x.second + 1));
    }
    if (x.second - 1 >= 0 && !visited1[x.first][x.second - 1] &&
        s[x.first][x.second - 1] == '0') {
      visited1[x.first][x.second - 1] = 1;
      q1.push(make_pair(x.first, x.second - 1));
    }
    en.push_back(make_pair(x.first, x.second));
  }
  int ans = dis(r1, c1, r2, c2), ma;
  for (int i = 0; i < st.size(); i++) {
    for (int j = 0; j < en.size(); j++) {
      ma = dis(st[i].first, st[i].second, en[j].first, en[j].second);
      ans = min(ans, ma);
    }
  }
  cout << ans;
}
