#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll ans = 0;
void init() { ans = 0; }
void input() { cin >> n; }
void solve() {
  ll inst = n;
  bool odd = n % 2;
  if (odd) {
    n--;
  }
  bool run = true;
  while (run) {
    if (n == 2) {
      ans += 1;
      run = false;
    } else if (n == 4) {
      ans += 3;
      run = false;
    } else if ((n / 2) % 2) {
      ans += n / 2;
      n /= 2;
      n--;
    } else {
      ans++;
      n -= 2;
    }
  }
  if (odd) {
    cout << inst - ans << '\n';
  } else {
    cout << ans << '\n';
  }
}
void output() {}
int main() {
  ios_base::sync_with_stdio(false);
  int number_of_testcases = 1;
  cin >> number_of_testcases;
  while (number_of_testcases--) {
    ans = 0;
    cin >> n;
    ll inst = n;
    bool odd = n % 2;
    if (odd) {
      n--;
    }
    while (n > 4) {
      if ((n / 2) % 2) {
        ans += n / 2;
        n /= 2;
        n--;
      } else {
        ans++;
        n -= 2;
      }
    }
    if (n == 4) {
      ans += 3;
    }
    if (n == 2) {
      ans += 1;
    }
    if (odd) {
      cout << inst - ans << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
