#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, A[100000], start, finish, k, ind, ans, i;
  cin >> n;
  i = 0;
  A[0] = -1;
  ind = 0;
  k = 0;
  ans = 1;
  start = 0;
  finish = 1;
  while (cin >> s) {
    i = i + s.length();
    if ((s[s.length() - 1] == '.') || (s[s.length() - 1] == '?') ||
        (s[s.length() - 1] == '!')) {
      ind++;
      A[ind] = i;
    }
    i++;
  }
  while (finish <= ind) {
    if (A[finish] - A[start] - 1 <= n) {
      finish++;
    } else {
      if (finish - start == 1) {
        k = 1;
        break;
      }
      ans++;
      start = finish - 1;
    }
  }
  if (k == 0) {
    cout << ans;
  } else {
    cout << "Impossible";
  }
}
