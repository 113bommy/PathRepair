#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  vector<long long> a;
  cin >> n >> x;
  int k;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    a.push_back(k);
  }
  sort(a.begin(), a.end());
  long long res = 0;
  for (int i = 0; i < a.size(); i++) {
    res = res + a[i] * x;
    if (x > 1) x--;
  }
  cout << res;
  return 0;
}
