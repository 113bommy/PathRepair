#include <bits/stdc++.h>
using namespace std;
bool prime(int p) {
  if (p <= 1) return false;
  for (int i = 2; i * i <= p; i++)
    if (p % i == 0) return false;
  return true;
}
int power(int a, int p, int m) {
  if (p == 0) return 1;
  int ans = power(a, p / 2, m);
  ans = (1LL * ans * ans) % m;
  if (p % 2) ans = (1LL * ans * a) % m;
  return ans;
}
vector<int> pf(int x) {
  vector<int> ans;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      ans.push_back(i);
    }
  if (x > 1) ans.push_back(x);
  return ans;
}
int solve(int p, int x) {
  if (!prime(p)) return -1;
  int n = p - 1;
  vector<int> pn = pf(n);
  for (int i = x - 1; i > 0; i--) {
    int y = i % p;
    if (y == 0) continue;
    bool b = true;
    for (int x : pn) {
      if (power(i, n / x, p) == 1) {
        b = false;
        break;
      }
    }
    if (b) return i;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  int p = n + 1;
  cout << solve(p, x) << endl;
}
