#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<double, int> m;
  vector<double> v;
  while (n--) {
    char ch;
    int a, b, c;
    cin >> ch >> a >> ch >> b >> ch >> ch >> c;
    m[(a + b) / c]++;
    v.push_back((a + b) / c);
  }
  for (auto x : v) cout << m[x] << " ";
  return 0;
}
