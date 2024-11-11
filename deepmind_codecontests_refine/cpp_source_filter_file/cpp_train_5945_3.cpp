#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long a_plus_b = a + b;
  vector<long long> div_a, div_b, div_ab;
  for (long long i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      div_a.push_back(i);
      if (i * i != a) {
        div_a.push_back(a / i);
      }
    }
  }
  for (long long i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      div_b.push_back(i);
      if (i * i != b) {
        div_b.push_back(b / i);
      }
    }
  }
  for (long long i = 1; i * i <= a_plus_b; i++) {
    if (a_plus_b % i == 0) {
      div_ab.push_back(i);
      if (i * i != a_plus_b) {
        div_ab.push_back(a_plus_b / i);
      }
    }
  }
  long long ans = 1e18;
  sort(div_a.begin(), div_a.end());
  sort(div_b.begin(), div_b.end());
  sort(div_ab.begin(), div_ab.end());
  for (auto d1 : div_ab) {
    vector<long long>::iterator it =
        lower_bound(div_a.begin(), div_a.end(), d1);
    if (it == div_a.end() || *it > d1) {
      if (it == div_a.begin()) {
        continue;
      } else {
        it--;
      }
    }
    long long d2 = *it;
    if (a_plus_b / d1 >= a / d2) {
      ans = min(ans, 2ll * (d1 + (a + b) / d1));
    }
  }
  swap(a, b);
  swap(div_a, div_b);
  for (auto d1 : div_ab) {
    vector<long long>::iterator it =
        lower_bound(div_a.begin(), div_a.end(), d1);
    if (it == div_a.end() || *it > d1) {
      if (it == div_a.begin()) {
        continue;
      } else {
        it--;
      }
    }
    long long d2 = *it;
    if (a_plus_b / d1 >= a / d2) {
      ans = min(ans, 2ll * (d1 + (a + b) / d2));
    }
  }
  cout << ans;
}
