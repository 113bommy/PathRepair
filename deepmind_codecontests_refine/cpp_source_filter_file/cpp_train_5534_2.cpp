#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  int k;
  cin >> n >> k;
  if (n < 1ll * (k * (k + 1)) / 2) {
    cout << "NO";
    return 0;
  }
  if ((n == 8 && k == 3) || (n == 4 && k == 2)) {
    cout << "NO";
    return 0;
  }
  if (k == 1) {
    cout << "YES"
         << "\n"
         << n;
    return 0;
  }
  if (k == 2 && n % 2 == 0) {
    cout << "YES"
         << "\n"
         << n / 2 - 1 << " " << n / 2 + 1;
    return 0;
  }
  if (k == 3 && n % 3 == 2) {
    cout << "YES"
         << "\n"
         << (n + 1) / 3 - 2 << " " << (n + 1) / 3 << " " << (n + 1) / 3 + 1;
    return 0;
  }
  cout << "YES"
       << "\n";
  long long inc = (n - 1ll * (k * (k + 1)) / 2) / k,
            rem = (n - 1ll * (k * (k + 1)) / 2) % k;
  if (rem == k - 1) {
    vector<long long> base;
    base.push_back(1);
    base.push_back(2);
    base.push_back(4);
    while (1) {
      if (base.size() == k - 1) {
        base.push_back(base.back() + 2);
        break;
      } else
        base.push_back(base.back() + 1);
    }
    for (auto j : base) cout << j + inc << " ";
  } else {
    vector<long long> ans;
    long long s = inc + 1;
    ans.push_back(inc + 1);
    while (1) {
      if (ans.size() == k - 1) {
        ans.push_back(n - s);
        break;
      } else {
        ans.push_back(ans.back() + 1);
        s += ans.back();
      }
    }
    for (auto j : ans) cout << j << " ";
  }
  return 0;
}
