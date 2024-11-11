#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt[27] = {0}, r = 0;
  string maze;
  cin >> n >> maze;
  r = n - 1;
  for (int i = 0; i < maze.size(); i++) {
    if ((i & 1) == 0)
      cnt[maze[i]]++;
    else {
      if (cnt[tolower(maze[i])] >= 1) {
        r--;
        cnt[tolower(maze[i])]--;
      }
    }
  }
  cout << r;
  return 0;
}
