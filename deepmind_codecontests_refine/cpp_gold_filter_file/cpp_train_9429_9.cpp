#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  int n;
  cin >> n;
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    long long in;
    cin >> in;
    a.push_back(in);
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < n - 1; i++) {
    long long x = a[i - 1];
    long long y = a[i];
    long long z = a[i + 1];
    if (x + y > z) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
