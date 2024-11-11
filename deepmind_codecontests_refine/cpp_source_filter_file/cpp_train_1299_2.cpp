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
using std::vector;
int main() {
  string data[1000];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> data[i];
  int row[1000] = {
      0,
  };
  int col[1000] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (data[i][j] == '*') {
        row[i]++;
        col[j]++;
      }
    }
  }
  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (data[i][j] != '*') continue;
      answer += (row[i] - 1) * (col[j] - 1);
    }
  }
  cout << answer;
  return 0;
}
