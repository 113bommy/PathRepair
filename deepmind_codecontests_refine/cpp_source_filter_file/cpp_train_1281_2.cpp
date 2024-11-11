#include <bits/stdc++.h>
using namespace std;
int i, a, b, c, d, x, y;
bool w;
int main() {
  vector<vector<int> > t(9);
  for (i = 1; i <= 4; i++) {
    cin >> a >> b >> c >> d;
    if (a != c && b != d) {
      cout << "NO";
      return 0;
    }
    if (a == c && b == d) {
      cout << 0;
      return 0;
    }
    if (a == c) {
      y++;
    }
    if (b == d) {
      x++;
    }
    t[i * 2 - 1].push_back(a);
    t[i * 2 - 1].push_back(b);
    t[i * 2].push_back(c);
    t[i * 2].push_back(d);
  }
  if (x != 2 || y != 2) {
    cout << "NO";
    return 0;
  }
  vector<vector<int> > v;
  vector<int> e;
  vector<int> used(9);
  for (i = 1; i <= 8; i++) {
    e.push_back(t[i][0]);
    e.push_back(t[i][1]);
    if (find(v.begin(), v.end(), e) == v.end())
      v.push_back(e);
    else {
      if (used[find(v.begin(), v.end(), e) - v.begin()] == 0) {
        used[find(v.begin(), v.end(), e) - v.begin()] = 1;
      } else {
        cout << "NO";
        return 0;
      }
    }
    e.clear();
  }
  if (v.size() == 4)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
