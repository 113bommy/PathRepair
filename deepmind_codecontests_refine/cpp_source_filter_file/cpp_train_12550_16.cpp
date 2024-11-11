#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, c, i, a, ct = 0;
  cin >> n >> c;
  vector<long long> v;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  for (i = 0; i < v.size() - 1; i++) {
    if (v[i + 1] - v[i] <= c) {
      ct++;
    } else {
      ct = 0;
    }
  }
  cout << ct;
  return 0;
}
