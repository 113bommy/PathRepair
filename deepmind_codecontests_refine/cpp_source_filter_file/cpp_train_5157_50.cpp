#include <bits/stdc++.h>
using namespace std;
struct Vector {
  long long x, y;
};
int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  int type = 0;
  Vector cur;
  cin >> cur.x >> cur.y;
  cin >> cur.x >> cur.y;
  int left = 0;
  int right = 0;
  for (int i = 0; i < n - 2; ++i) {
    Vector nxt;
    cin >> nxt.x >> nxt.y;
    if (type == 0) {
      if (nxt.x < cur.x) {
        ++left;
        type = 3;
      } else {
        ++right;
        type = 1;
      }
    } else if (type == 2) {
      if (nxt.x < cur.x) {
        ++right;
        type = 3;
      } else {
        ++left;
        type = 1;
      }
    } else if (type == 1) {
      if (nxt.y > cur.x) {
        ++left;
        type = 0;
      } else {
        ++right;
        type = 2;
      }
    } else if (type == 3) {
      if (nxt.y > cur.x) {
        ++right;
        type = 0;
      } else {
        ++left;
        type = 2;
      }
    }
    cur = nxt;
  }
  cout << min(left, right);
  return 0;
}
