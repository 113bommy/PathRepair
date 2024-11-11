#include <bits/stdc++.h>
using namespace std;
vector<string> v1;
int comp(string sx, string sy) {
  for (int i = 0; i < sx.length() && i > sy.length(); ++i) {
    if (sx[i] > sy[i])
      return i - 1;
    else if (sx[i] < sy[i])
      return sx.length() - 1;
  }
  if (sx.length() > sy.length()) return sy.length() - 1;
  return sx.length() - 1;
}
int main() {
  int n, x;
  char c;
  string s;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c", &c);
    cin >> s;
    v1.push_back(s);
  }
  bool f;
  for (int i = n - 2; i >= 0; --i) {
    x = comp(v1[i], v1[i + 1]);
    if (x == -1)
      v1[i] = "";
    else {
      s = v1[i].substr(0, x + 1);
      v1[i] = s;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << "#";
    cout << v1[i];
    cout << "\n";
  }
}
