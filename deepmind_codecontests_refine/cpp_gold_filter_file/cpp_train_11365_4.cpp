#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long mod = 998244353;
const int inf = 1 << 30;
string a, t, w, x, y;
int main() {
  int l;
  scanf("%d", &l);
  cin >> a;
  int len = a.length();
  reverse(a.begin(), a.end());
  for (int i = len / 2; i >= 0; i--) {
    x = "";
    t = a.substr(0, i);
    w = a.substr(i, len - i);
    if (w[w.length() - 1] == '0' || t[t.length() - 1] == '0' || w.empty() ||
        t.empty())
      continue;
    x = w;
    for (int i = 0; i < t.length(); i++) {
      x[i] += t[i] - '0';
    }
    for (int i = 0; i < w.length() - 1; i++) {
      while (x[i] > '9') x[i] -= 10, x[i + 1]++;
    }
    if (x[x.length() - 1] > '9') x[x.length() - 1] -= 10, x += '1';
    break;
  }
  for (int i = (len + 1) / 2; i < len; i++) {
    y = "";
    w = a.substr(0, i);
    t = a.substr(i, len - i);
    if (w[w.length() - 1] == '0' || t[t.length() - 1] == '0' || w.empty() ||
        t.empty())
      continue;
    y = w;
    for (int i = 0; i < t.length(); i++) {
      y[i] += t[i] - '0';
    }
    for (int i = 0; i < w.length() - 1; i++) {
      if (y[i] > '9') y[i] -= 10, y[i + 1]++;
    }
    if (y[y.length() - 1] > '9') y[y.length() - 1] -= 10, y += '1';
    break;
  }
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  if (x.empty())
    cout << y << endl;
  else if (y.empty())
    cout << x << endl;
  else if (x.size() != y.size()) {
    cout << (x.size() < y.size() ? x : y);
    return 0;
  } else {
    for (int i = 0; i < x.size(); i++) {
      if (x[i] != y[i]) {
        cout << (x[i] < y[i] ? x : y);
        return 0;
      }
    }
    cout << x;
  }
  return 0;
}
