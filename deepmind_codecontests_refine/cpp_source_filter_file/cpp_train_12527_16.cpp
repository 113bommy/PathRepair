#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double pii = 3.14159265359;
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001;
void no() {
  cout << "NO" << nl;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> str;
  int N = (int)(str).size();
  int ls = -1;
  vector<string> v1, v2;
  for (int x = 0; x < (N); x++) {
    if (str[x] == '.') {
      if (x == 0 || x > 9) {
        no();
      }
      v1.push_back(str.substr(0, x));
      ls = x;
      break;
    }
  }
  for (int x = ls + 1; x < (N); x++) {
    if (str[x] == '.') {
      if (x - ls <= 2 || x - ls > 12) {
        no();
      } else if (x - ls <= 7) {
        v2.push_back(str.substr(ls + 1, 1));
        v1.push_back(str.substr(ls + 2, x - ls - 2));
      } else {
        v2.push_back(str.substr(ls + 1, 3));
        v1.push_back(str.substr(ls + 4, x - ls - 4));
      }
      ls = x;
    }
  }
  if (ls == -1 || N - 1 - ls == 0 || N - 1 - ls > 4) {
    no();
  } else {
    v2.push_back(str.substr(ls + 1));
  }
  cout << "YES" << nl;
  for (int x = 0; x < ((int)(v1).size()); x++)
    cout << v1[x] << '.' << v2[x] << nl;
  return 0;
}
