#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int re = 1000000000;
  for (int i = 0; i < n / 2; i++) {
    re = min(re, a[i + n / 2] - a[i]);
  }
  cout << re << endl;
  return 0;
}
