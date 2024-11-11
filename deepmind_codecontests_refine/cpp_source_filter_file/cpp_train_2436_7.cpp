#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int p, q;
  cin >> p >> q;
  cin >> s;
  int n = s.length();
  vector<pair<int, int> > v1, v2;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    v1.push_back(make_pair(x, y));
    if (x == p && y == q) {
      cout << "Yes";
      return 0;
    }
    if (s[i] == 'R') {
      x++;
    } else if (s[i] == 'L') {
      x--;
    } else if (s[i] == 'U') {
      y++;
    } else {
      y--;
    }
  }
  for (int i = 0; i < n; i++) {
    v2.push_back(make_pair(x, y));
    if (x == p && y == q) {
      cout << "Yes";
      return 0;
    }
    if (s[i] == 'R') {
      x++;
    } else if (s[i] == 'L') {
      x--;
    } else if (s[i] == 'U') {
      y++;
    } else {
      y--;
    }
  }
  for (int i = 0; i < n; i++) {
    int j = v2[i].first - v1[i].first;
    int k = v2[i].second - v1[i].second;
    int e = p - v1[i].first;
    int r = q - v1[i].second;
    if (j == 0 && k == 0) {
      if (e == 0 && r == 0) {
        cout << "Yes";
        return 0;
      }
    } else if (j == 0) {
      if ((r / k > 0) && (r % k == 0) && v2[i].first == x) {
        cout << "Yes";
        return 0;
      }
    } else if (k == 0) {
      if ((e / j > 0) && (e % j == 0) && v1[i].second == y) {
        cout << "Yes";
        return 0;
      }
    } else if ((e / j > 0) && (e % j == 0) && (r / k > 0) && (r % k == 0) &&
               e / j == r / k) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
