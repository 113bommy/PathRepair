#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p;
  scanf("%lld %lld", &n, &p);
  vector<string> v;
  for (long long i = 0; i < n; i++) {
    string second;
    cin >> second;
    v.push_back(second);
  }
  long long cur = 0, ans = 0;
  for (long long i = n; --i >= 0;) {
    if (v[i] == "half") {
      ans += cur * 2;
      cur = cur * 2;
    } else {
      ans += 1 + cur * 2;
      cur = cur * 2 + 1;
    }
  }
  cout << ans * p / 2;
}
