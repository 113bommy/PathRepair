#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int fexp(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    b /= 2;
    a = a * a % 1000000007;
  }
  return ans;
}
long long int inverse(long long int a, long long int p) {
  return fexp(a, p - 2);
}
void ingraph(vector<vector<long long int> >& graph, long long int m) {
  long long int x, y;
  for (long long int i = 0; i < m; i++) {
    cin >> x >> y;
    x--, y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
}
long long int modify(long long int n) {
  long long int res = n;
  res %= 1000000007;
  res += 1000000007;
  res %= 1000000007;
  return res;
}
long long int min(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
void solve() {
  long long int n, a, b;
  cin >> n;
  vector<long long int> v(n + 1);
  v[0] = n + 1;
  v[1] = 1;
  for (int i = 2; i < n + 1; i++) {
    if (v[i] != 0) continue;
    for (int j = i; j <= n; j = j + i) {
      if (v[j] != 0)
        continue;
      else
        v[j] = j / i;
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main() {
  long long int n = 1;
  while (n--) {
    solve();
  }
  return 0;
}
