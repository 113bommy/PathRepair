#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vll = vector<ll>;
using vii = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ull = unsigned long long int;
ll To_int(string str) {
  stringstream ss(str);
  ll x = 0;
  ss >> x;
  return x;
}
template <typename T>
T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
void input() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vii ara(n);
  for (int i = 0; i < n; i++) cin >> ara[i];
  sort((ara).begin(), (ara).end());
  ll sum = (ll)ara.back();
  for (int i = n - 2; i >= 0; i--) {
    if (ara[i] >= ara[i + 1]) ara[i] = ara[i + 1] - 1;
    if (ara[i]) sum += ara[i];
  }
  cout << sum;
  return 0;
}
