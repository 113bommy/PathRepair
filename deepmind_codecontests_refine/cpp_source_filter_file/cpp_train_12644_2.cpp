#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, p[100005], i;
  cin >> n;
  char strng[55];
  vector<string> str;
  for (i = 0; i < 2 * n; i++) {
    cin >> strng;
    str.push_back(strng);
  }
  int x;
  for (i = 0; i < n; i++) {
    cin >> x;
    p[i] = x - 1;
  }
  string a, b, c, d;
  a = str[2 * p[0]];
  b = str[2 * p[0] + 1];
  if (a > b) swap(a, b);
  int h = 2;
  for (i = 1; i < n; i++) {
    c = str[2 * p[i]];
    d = str[2 * p[i] + 1];
    if (c > d) swap(c, d);
    if (a < d) {
      h = 2;
      a = c;
      b = d;
    } else if (a > d) {
      h = 0;
      break;
    } else if (a > c && a < d) {
      h = 1;
      a = d;
      b = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    } else if (a > c && a > d) {
      h = 0;
      break;
    }
  }
  if (h == 0)
    cout << "NO" << '\n';
  else
    cout << "YES" << '\n';
  return 0;
}
