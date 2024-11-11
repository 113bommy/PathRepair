#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int t, st = 0, en = 2e9;
  cin >> t;
  long long int result = 1e11;
  for (long long int i = 0; i < t; i++) {
    string s;
    char r;
    long long int n;
    cin >> s >> n >> r;
    bool y = (r == 'Y');
    if (s == ">=") {
      if (y) {
        st = max(n, st);
      } else {
        en = min(en, n - 1);
      }
    } else if (s == "<=") {
      if (y) {
        en = min(n, en);
      } else {
        st = max(n + 1, st);
      }
    } else if (s == ">") {
      if (y) {
        st = max(n + 1, st);
      } else {
        en = min(n, en);
      }
    } else if (s == "<") {
      if (y) {
        en = min(n - 1, en);
      } else {
        st = max(n, st);
      }
    }
  }
  for (long long int i = st; i <= en; i++) {
    result = i;
    break;
  }
  if (result == 1e11) {
    cout << "Impossible";
  } else {
    cout << result;
  }
}
