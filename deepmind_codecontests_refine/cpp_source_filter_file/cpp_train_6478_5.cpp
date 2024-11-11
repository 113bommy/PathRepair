#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  int t;
  cin >> t;
  int c = 0, co = 0, co1 = 0;
  std::vector<int> v, v1;
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    v1.push_back(a);
  }
  for (int i = 0; i < t; i++) {
    if (v[i] == 1 && v1[i] == 0) {
      c++;
    }
    if (v[i] == 1) co++;
    if (v1[i] == 1) co1++;
  }
  int ans = 0;
  if (co > co1) {
    cout << 0;
  } else if (c > 0) {
    co1 = co1 - co;
    co1++;
    ans = co1 / c;
    if (co1 % c > 0) {
      ans++;
    }
    ans++;
    cout << ans;
  } else {
    cout << -1;
  }
  cout << "\n";
  return 0;
}
