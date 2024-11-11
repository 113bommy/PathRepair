#include <bits/stdc++.h>
using namespace std;
int n;
long long a, s;
vector<long long> t;
long long k;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    t.push_back(a);
  }
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  s = 0;
  k = t[0] + 1;
  for (auto x : t) {
    k = max(0ll, min(x, k - 1));
    s += k;
  }
  cout << s;
  return 0;
}
