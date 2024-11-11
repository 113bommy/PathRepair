#include <bits/stdc++.h>
using namespace std;
const int N = (1e5);
long long a[N];
string L = "L";
string R = "R";
string solve(int a[], int c, int l, int r) {
  string s = "";
  if (c >= a[r] && c >= a[l]) return s;
  if (l > r) return s;
  if (c < a[l] && c < a[r]) {
    if (a[l] < a[r]) {
      return L + solve(a, a[l], l + 1, r);
    } else if (a[l] > a[r]) {
      return R + solve(a, a[r], l, r - 1);
    } else {
      string ls = L + solve(a, a[l], l + 1, r);
      string rs = R + solve(a, a[r], l, r - 1);
      return (ls.size() > rs.size() ? ls : rs);
    }
  } else if (c < a[r]) {
    return R + solve(a, a[r], l, r - 1);
  } else if (c < a[l]) {
    return L + solve(a, a[l], l + 1, r);
  } else {
  }
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int i, a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  string s = solve(a, -1, 0, n - 1);
  cout << s.size() << endl;
  cout << s << endl;
  return 0;
}
