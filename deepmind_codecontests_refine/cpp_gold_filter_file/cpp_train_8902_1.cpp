#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::sort;
using std::string;
using std::vector;
int main() {
  int n;
  cin >> n;
  char kuda[100000] = {
      0,
  };
  int dlina[100000] = {
      0,
  };
  int visited[100000] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    cin >> kuda[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> dlina[i];
  }
  int cur = 0;
  visited[0] = 1;
  for (int i = 0; i < 100001; i++) {
    if (kuda[cur] == '>') {
      cur += dlina[cur];
    } else {
      cur -= dlina[cur];
    }
    if (cur < 0 || cur >= n) {
      cout << "FINITE";
      return 0;
    } else {
      if (visited[cur] == 1) {
        cout << "INFINITE";
        return 0;
      } else {
        visited[cur] = 1;
      }
    }
  }
  return 0;
}
