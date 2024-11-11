#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;
const int LOG = 20;
const int cntsz = 101;
const int INF = 1e9;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long ans = 1;
  string t;
  int x;
  set<int> buy, sell, both;
  for (int i = 0; i < int(n); i++) {
    cin >> t >> x;
    if (t == "ADD") {
      if (!buy.empty() && x < *buy.begin()) {
        buy.insert(x);
      } else if (!sell.empty() && x > *sell.begin()) {
        sell.insert(x);
      } else {
        both.insert(x);
      }
    } else {
      if (buy.find(x) != buy.end()) {
        if (x == *buy.begin()) {
          buy.erase(x);
        } else {
          cout << "0\n";
          return 0;
        }
      } else if (sell.find(x) != sell.end()) {
        if (x == *sell.begin()) {
          sell.erase(x);
        } else {
          cout << "0\n";
          return 0;
        }
      } else {
        both.erase(x);
        ans *= 2;
        ans %= mod;
      }
      for (int y : both) {
        if (y < x)
          buy.insert(y);
        else
          sell.insert(y);
      }
      both.clear();
    }
  }
  ans *= ((int)(both).size() + 1);
  ans %= mod;
  cout << ans << "\n";
  return 0;
}
