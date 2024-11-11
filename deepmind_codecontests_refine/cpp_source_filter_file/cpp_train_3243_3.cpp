#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int POWER[65];
long long int power(long long int x, long long int y, long long int mod) {
  long long int res = 1;
  x %= mod;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y >>= 1;
    x = (x * x) % mod;
  }
  return res;
}
vector<long long int> adj[2 * 100000 + 5];
bool vis[2 * 100000 + 5];
bool areParanthesisBalanced(string expr) {
  stack<char> s;
  char x;
  for (long long int i = 0; i < expr.length(); i++) {
    if (expr[i] == '(') {
      s.push(expr[i]);
      continue;
    }
    if (s.empty()) return false;
    switch (expr[i]) {
      case ')':
        x = s.top();
        s.pop();
        if (x == '{' || x == '[') return false;
        break;
      case '}':
        x = s.top();
        s.pop();
        if (x == '(' || x == '[') return false;
        break;
      case ']':
        x = s.top();
        s.pop();
        if (x == '(' || x == '{') return false;
        break;
    }
  }
  return (s.empty());
}
int main() {
  long long int n, a, b;
  cin >> n >> a >> b;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int ans = 0;
  long long int x = a, y = b;
  for (long long int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      if (x > 0 && y < b) {
        x--;
        y = max(y + 1, b);
        ans++;
      } else if (y > 0) {
        y--;
        ans++;
      } else if (y == 0) {
        if (x > 0) {
          x--;
          y = max(y + 1, b);
          ans++;
        } else {
          cout << ans;
          return 0;
        }
      }
    } else {
      if (y > 0) {
        y--;
        ans++;
      } else if (x > 0) {
        x--;
        ans++;
      } else {
        cout << ans;
        return 0;
      }
    }
  }
  cout << ans;
}
