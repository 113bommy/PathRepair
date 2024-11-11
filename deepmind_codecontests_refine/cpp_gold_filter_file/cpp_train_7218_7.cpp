#include <bits/stdc++.h>
using namespace std;
long long int expo(long long int x, long long int n, long long int M) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * x) % M;
    }
    x = (x * x) % M;
    n /= 2;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  string str;
  cin.ignore();
  getline(cin, str);
  istringstream is(str);
  if (n == 1) {
    string s;
    is >> s;
    if (s != "int" || is >> s)
      cout << "Error occurred" << endl;
    else
      cout << "int" << endl;
    return;
  }
  string s, ans = "";
  vector<long long int> v;
  long long int f = 1, i = 0;
  while (i < n) {
    is >> s;
    if (s == "int") i++;
    if (f) {
      if (s == "pair") {
        ans += "pair<";
        if (!v.empty()) v.back()++;
        v.push_back(0);
      } else {
        while (!v.empty() && v.back() == 2) {
          v.pop_back();
          if (!v.empty() && v.back() == 2)
            ans += ">";
          else
            ans += ">,";
        }
        if (v.empty()) {
          f = 0;
          continue;
        }
        if (v.back() == 0) {
          ans += "int,";
        } else {
          ans += "int";
        }
        v.back()++;
        while (!v.empty() && v.back() == 2) {
          v.pop_back();
          if ((!v.empty() && v.back() == 2) || v.empty())
            ans += ">";
          else
            ans += ">,";
        }
      }
    }
  }
  if (!(f && v.empty()) || is >> s) {
    cout << "Error occurred" << endl;
  } else
    cout << ans << endl;
}
int main() {
  long long int t = 1, test = 0;
  while (t--) {
    solve();
  }
  return 0;
}
