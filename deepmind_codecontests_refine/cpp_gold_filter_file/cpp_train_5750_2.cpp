#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  set<long long> haveNoPresents;
  set<long long> haveNoPresentsAndDontKnow;
  vector<long long> f(n);
  for (long long i = 1; i <= n; ++i) {
    haveNoPresents.insert(i);
  }
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    f[i] = x;
    if (x != 0) {
      haveNoPresents.erase(x);
    }
  }
  for (long long i = 0; i < n; ++i) {
    if (f[i] == 0 && haveNoPresents.count(i + 1)) {
      haveNoPresentsAndDontKnow.insert(i + 1);
    }
  }
  for (long long i = 0; i < n; ++i) {
    if (f[i] != 0) {
      cout << f[i] << ' ';
    } else {
      long long mi = i + 1;
      if (!haveNoPresentsAndDontKnow.empty()) {
        mi = *haveNoPresentsAndDontKnow.rbegin();
      }
      if (mi == i + 1) {
        mi = *haveNoPresents.begin();
      }
      if (mi == i + 1) {
        mi = *haveNoPresents.rbegin();
      }
      haveNoPresents.erase(mi);
      haveNoPresentsAndDontKnow.erase(mi);
      cout << mi << ' ';
    }
  }
  return 0;
}
