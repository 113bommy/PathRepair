#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, i, l = 0, r, tmp;
  string rs;
  cin >> n;
  r = n - 1;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  tmp = 0;
  while (l != r) {
    if (a[r] > tmp && (a[r] < a[l] || a[l] < tmp)) {
      tmp = a[r];
      rs.push_back('R');
      r--;
    } else if (a[l] > tmp && (a[l] < a[r] || a[r] < tmp)) {
      tmp = a[l];
      rs.push_back('L');
      l++;
    } else
      break;
  }
  if (a[(l + r) / 2] > tmp && r - l == 1) rs.push_back('L');
  cout << rs.size() << endl << rs;
  return 0;
}
