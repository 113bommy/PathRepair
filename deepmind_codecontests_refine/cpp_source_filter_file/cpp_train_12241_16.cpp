#include <bits/stdc++.h>
using namespace std;
vector<int> h;
vector<vector<char> > a(500, vector<char>(500, ' '));
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  h.resize(n);
  int k = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    k += s[i] == '[' ? 1 : -1;
    mx = max(mx, abs(k));
  }
  h[0] = mx - 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1] && s[i] == ']')
      h[i] = h[i - 1] + 1;
    else if (s[i] == s[i - 1] && s[i] == '[')
      h[i] = h[i - 1] - 1;
    else
      h[i] = h[i - 1];
  }
  int j = 0, mid = mx;
  for (int i = 0; i < n; ++i) {
    a[mid - h[i] - 1][j] = a[mid + h[i] + 1][j] = '+';
    if (s[i] == '[')
      a[mid - h[i] - 1][j + 1] = a[mid + h[i] + 1][j + 1] = '-';
    else
      a[mid - h[i] - 1][j - 1] = a[mid + h[i] + 1][j - 1] = '-';
    for (int x = mid - h[i]; x <= mid + h[i]; ++x) a[x][j] = '|';
    if (i != n - 1 && s[i] != s[i + 1] && s[i] == '[') j += 4;
    j++;
  }
  for (int i = 0; i < 2 * mx + 3; ++i) {
    for (int x = 0; x < j; ++x) cout << a[i][x];
    cout << endl;
  }
  return 0;
}
