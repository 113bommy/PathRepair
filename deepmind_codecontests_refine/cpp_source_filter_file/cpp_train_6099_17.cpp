#include <bits/stdc++.h>
using namespace std;
int A[200005] = {0};
int n, m;
int ans = -1;
bool isSubsequence(string s, string t) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[k]) {
      k++;
      if (k == m) return true;
    }
  }
  return false;
}
void binsearch(string s, string t) {
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    string tmp = s;
    for (int i = 0; i < mid; i++) {
      tmp[A[i] - 1] = '.';
    }
    if (isSubsequence(tmp, t)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else
      r = mid - 1;
  }
}
int main() {
  string s, t;
  cin >> s >> t;
  n = s.length();
  m = t.length();
  for (int i = 0; i < n; i++) cin >> A[i];
  binsearch(s, t);
  cout << ans << "\n";
  return 0;
}
