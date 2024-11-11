#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;
  string s;
  cin >> n >> t >> s;
  int dec = n;
  for (int i = (0); i < (n); i++) {
    if (s[i] == '.') dec = i;
  }
  if (dec == n) {
    cout << s << '\n';
    return 0;
  }
  string a = s.substr(0, dec), b = s.substr(dec + 1);
  int c = 0, end = (int)b.size();
  for (int k = (0); k < ((int)b.size()); k++) {
    if (b[k] < '5') continue;
    for (int i = k; i >= 0; i--) {
      if (!t) break;
      if (b[i + 1] > '4') {
        end = i + 1;
        b[i]++;
        t--;
      }
    }
    break;
  }
  if (b[0] > '9' || (t && b[0] > '4')) {
    c = 1;
  }
  for (int i = (0); i < ((int)b.size()); i++)
    if (b[i] > '9') b[i] = '0';
  if (c) {
    for (int i = (int)a.size() - 1; i >= 0; i--) {
      a[i] += c;
      c = 0;
      if (a[i] > '9') a[i] = '0', c = 1;
    }
    if (c) a = "1" + a;
    cout << a << '\n';
  } else {
    cout << a << "." << b.substr(0, end) << '\n';
  }
  return 0;
}
