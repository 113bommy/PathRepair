#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  int max = INT_MIN;
  int c;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (max < v[i]) {
      max = v[i];
      c = i;
    }
  }
  if (c == 0) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i] < v[i + 1]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  } else if (c == n - 1) {
    for (int i = 0; i < n - 1; i++) {
      if (v[i] > v[i + 1]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  } else {
    for (int i = 0; i < c - 1; i++) {
      if (v[i] > v[i + 1]) {
        cout << "NO";
        return 0;
      }
    }
    for (int i = c + 1; i < n - 1; i++) {
      if (v[i] < v[i + 1]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  }
}
