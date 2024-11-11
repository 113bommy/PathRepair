#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
int n;
int arr[1000], cost[1000];
map<int, int> dp[305];
int recur(int ind, int x) {
  if (ind > n || ind < 0) return 0;
  if (ind == n && x != 1) return 1000000000;
  if (ind == n && x == 1) return 0;
  if (dp[ind].find(x) != dp[ind].end()) return dp[ind][x];
  int ans = 0, i;
  if (x == 0)
    ans += min(recur(ind + 1, x), recur(ind + 1, arr[ind]) + cost[ind]);
  else
    ans += min(recur(ind + 1, x), recur(ind + 1, gcd(arr[ind], x)) + cost[ind]);
  dp[ind][x] = ans;
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  int x = 1, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 1) {
      x = gcd(arr[i], arr[i - 1]);
    } else if (i > 1) {
      x = gcd(arr[i], x);
    }
  }
  for (i = 0; i < n; i++) cin >> cost[i];
  if (x > 1) {
    cout << "-1\n";
    return 0;
  } else {
    int xx = recur(0, 0);
    if (xx < 1000000000)
      cout << x << endl;
    else
      cout << "-1\n";
  }
  return 0;
}
