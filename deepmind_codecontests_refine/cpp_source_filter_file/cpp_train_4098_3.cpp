#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:20000000")
using namespace std;
const long long mod = 1000000007;
const double eps = 1e-7;
const long long INF = 1000000000000000;
int main() {
  string s;
  cin >> s;
  int x = -1, k = 0;
  for (int(i) = (0); (i) < (s.size()); ++(i)) {
    if (s[i] == '@') {
      x = i;
      k++;
    }
  }
  if (k == 0 || k > 1 || x > 16 || x == 0) {
    cout << "NO";
    return 0;
  }
  for (int(i) = (0); (i) < (x); ++(i)) {
    bool p = 0;
    if (s[i] >= 'a' && s[i] <= 'z') p = 1;
    if (s[i] >= 'A' && s[i] <= 'Z') p = 1;
    if (s[i] >= '0' && s[i] <= '9') p = 1;
    if (s[i] == '_') p = 1;
    if (!p) {
      cout << "NO";
      return 0;
    }
  }
  int y = -1;
  k = 0;
  for (int(i) = (x); (i) < (s.size()); ++(i))
    if (s[i] == '/') {
      y = i;
      k++;
    }
  if (k > 1) {
    cout << "NO";
    return 0;
  }
  if (y == -1) y = s.size() - 1;
  if (y - x - 1 > 32 || y - x - 1 < 1) {
    cout << "NO";
    return 0;
  }
  string d = "";
  for (int(i) = (x + 1); (i) < (y); ++(i))
    if (s[i] == '.') {
      if (d.size() < 1 || d.size() > 16) {
        cout << "NO";
        return 0;
      }
      for (int(j) = (0); (j) < (d.size()); ++(j)) {
        bool p = 0;
        if (d[j] >= 'a' && d[j] <= 'z') p = 1;
        if (d[j] >= 'A' && d[j] <= 'Z') p = 1;
        if (d[j] >= '0' && d[j] <= '9') p = 1;
        if (d[j] == '_') p = 1;
        if (!p) {
          cout << "NO";
          return 0;
        }
      }
      d = "";
    } else
      d += s[i];
  if (d.size() < 1 || d.size() > 16) {
    cout << "NO";
    return 0;
  }
  for (int(j) = (0); (j) < (d.size()); ++(j)) {
    bool p = 0;
    if (d[j] >= 'a' && d[j] <= 'z') p = 1;
    if (d[j] >= 'A' && d[j] <= 'Z') p = 1;
    if (d[j] >= '0' && d[j] <= '9') p = 1;
    if (d[j] == '_') p = 1;
    if (!p) {
      cout << "NO";
      return 0;
    }
  }
  if (k) {
    d = "";
    for (int(i) = (y + 1); (i) < (s.size()); ++(i)) d += s[i];
    if (d.size() < 1 || d.size() > 16) {
      cout << "NO";
      return 0;
    }
    for (int(j) = (0); (j) < (d.size()); ++(j)) {
      bool p = 0;
      if (d[j] >= 'a' && d[j] <= 'z') p = 1;
      if (d[j] >= 'A' && d[j] <= 'Z') p = 1;
      if (d[j] >= '0' && d[j] <= '9') p = 1;
      if (d[j] == '_') p = 1;
      if (!p) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
