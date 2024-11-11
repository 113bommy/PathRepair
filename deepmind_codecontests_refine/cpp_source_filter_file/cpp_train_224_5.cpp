#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool comp(pair<int, pair<int, char>> a, pair<int, pair<int, char>> b) {
  if (a.first < b.first) {
    return 1;
  }
  if (a.first == b.first && a.second.second - 'a' < b.second.second - 'a') {
    return 1;
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    int mini = 100000000, maxi = 0;
    for (int j = 0; j < t; j++) {
      int a, b;
      cin >> a >> b;
      mini = min(b, mini);
      maxi = max(a, maxi);
    }
    int l = maxi - mini;
    if (l < 0) {
      l = 0;
    }
    cout << l << endl;
  }
}
