#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::to_string;
using std::vector;
int main() {
  int answer = 0;
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  int len1 = 0;
  int len2 = 0;
  if (y1 == 0) {
    len1 = x1;
  } else if (x1 == n) {
    len1 = n + y1;
  } else if (y1 == n) {
    len1 = n + n + n - x1;
  } else {
    len1 = 4 * n - y1;
  }
  if (y2 == 0) {
    len2 = x2;
  } else if (x2 == n) {
    len2 = n + y2;
  } else if (y2 == n) {
    len2 = n + n + n - x2;
  } else {
    len2 = 4 * n - y2;
  }
  cout << min((len1 - len2 + 4 * n) % (4 * n), (len2 - len1 + 4 * n) % (4 * n));
  return 0;
}
