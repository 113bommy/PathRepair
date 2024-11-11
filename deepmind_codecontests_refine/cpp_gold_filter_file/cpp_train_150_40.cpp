#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string str;
  cin >> str;
  bool good = false;
  for (long long int i = (1); i <= (long long int)(30); ++i) {
    for (long long int j = (0); j <= (long long int)(n); ++j) {
      if (j + (i * 4) >= n)
        break;
      else if (str[j] == '*' && str[j + i] == '*' && str[j + (2 * i)] == '*' &&
               str[j + (3 * i)] == '*' && str[j + (4 * i)] == '*') {
        good = true;
      }
    }
  }
  if (good)
    cout << "yes";
  else
    cout << "no";
}
