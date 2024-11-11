#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int MAXINT = 2e9;
ll MAXLL = 9e18;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<int> dels;
  for (int i = (2); i < (int)(sqrt(n) + 3); ++i) {
    if (n % i == 0) {
      dels.insert(i);
      dels.insert(n / i);
    }
  }
  vector<int> dead;
  for (auto shift : dels) {
    bool deadflag = false;
    for (int i = (0); i < (int)(shift); ++i) {
      int ones = 0;
      for (int now = i; now < n; now += shift) {
        if (s[now] != '0') ones++;
      }
      if (ones % 2 != 0) deadflag = true;
    }
    if (deadflag) dead.push_back(shift);
  }
  int ans = 0;
  for (int i = (1); i < (int)(n + 1); ++i) {
    bool ok = true;
    for (auto a : dead) {
      if (i % a == 0) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans;
}
