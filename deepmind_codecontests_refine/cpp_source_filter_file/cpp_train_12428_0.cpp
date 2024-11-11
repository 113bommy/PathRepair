#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  if (!v.back()) {
    cout << ((n + 1) * n) / 2;
  } else {
    long long moves = 0;
    for (int i = 0; i < n; i++) moves += abs(i - v[i]) + 1;
    cout << moves;
  }
  return 0;
}
