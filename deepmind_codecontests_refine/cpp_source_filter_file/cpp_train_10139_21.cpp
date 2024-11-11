#include <bits/stdc++.h>
using namespace std;
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int((name).size())) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long mcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool prime(long long n, long long i) {
  if (i > sqrt(n)) return true;
  if (n % i == 0)
    return false;
  else
    return prime(n, i + 1);
}
struct compii {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == a.second) return a.second < b.second;
    return a.first > b.first;
  }
};
bool comp(int a, int b) { return a > b; }
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  int n, m;
  cin >> n >> m;
  int a = n / m;
  int b = n % m;
  for (int i = 0; i < n; i++) {
    if (b)
      cout << a + 1 << " ", b--;
    else
      cout << a << " ";
  }
  cout << endl;
}
int main() {
  setIO("");
  int t = 1;
  while (t-- > 0) solve();
  return 0;
}
