#include <bits/stdc++.h>
using namespace std;
string typo(string s) {
  int cnt = 0;
  string ans = "";
  ans = ans + s[0];
  for (long long i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
      if (cnt < 2) ans = ans + s[i - 1];
    } else {
      cnt = 0;
      ans = ans + s[i];
    }
  }
  return ans;
}
string typo2(string s) {
  int cnt = 0;
  string ans = "";
  for (long long i = 0, j = 1; i < s.size() && j < s.size(); i++, j++) {
    if (s[i] == s[j]) {
      cnt++;
      if (cnt % 2 != 0)
        ans = ans + s[i] + s[j];
      else
        ans = ans + s[i];
    } else {
    }
  }
  return ans;
}
int main() {
  int n, cnt = 1, mx = 1, mxcnt = 1;
  cin >> n;
  long long A[n];
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    mx = ((mx) > (A[i]) ? (mx) : (A[i]));
  }
  for (int i = 1; i < n; i++) {
    if (A[i] == A[i - 1] && A[i] == mx)
      cnt++;
    else
      cnt = 1;
    mxcnt = ((mxcnt) > (cnt) ? (mxcnt) : (cnt));
  }
  cout << mxcnt << endl;
  return 0;
}
