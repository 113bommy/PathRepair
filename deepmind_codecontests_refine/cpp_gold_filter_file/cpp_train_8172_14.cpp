#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  unordered_map<int, int> d1, d2;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    d1[x + y]++;
    d2[x - y]++;
  }
  long long ans = 0;
  for (auto a : d1) {
    long long val = a.second;
    ans += (val * (val - 1)) / 2;
  }
  for (auto a : d2) {
    long long val = a.second;
    ans += (val * (val - 1)) / 2;
  }
  cout << ans;
}
