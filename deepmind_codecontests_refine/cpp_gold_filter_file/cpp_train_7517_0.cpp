#include <bits/stdc++.h>
using namespace std;
long long int dfs(long long int x, long long int y, long long int i,
                  vector<pair<long long int, long long int>> heykel) {
  if (x < 0 || x > 7 || y < 0 || y > 7) return 0;
  for (auto &it : heykel)
    if ((it.first++ == x || it.first == x) && it.second == y) return 0;
  bool tmp = 1;
  for (auto it : heykel)
    if (it.first <= x) tmp = 0;
  if (tmp || (x == 0 && y == 7)) return 1;
  return (dfs(x - 1, y - 1, i + 1, heykel) || dfs(x - 1, y, i + 1, heykel) ||
          dfs(x - 1, y + 1, i + 1, heykel) || dfs(x, y - 1, i + 1, heykel) ||
          dfs(x, y, i + 1, heykel) || dfs(x, y + 1, i + 1, heykel) ||
          dfs(x + 1, y - 1, i + 1, heykel) || dfs(x + 1, y, i + 1, heykel) ||
          dfs(x + 1, y + 1, i + 1, heykel));
}
int main() {
  vector<pair<long long int, long long int>> heykel;
  char a;
  for (long long int i = 0; i < 8; i++) {
    for (long long int j = 0; j < 8; j++) {
      cin >> a;
      if (a == 'S') heykel.push_back(make_pair(i, j));
    }
  }
  if (dfs(6, 0, 1, heykel) || dfs(6, 1, 1, heykel) || dfs(7, 1, 1, heykel) ||
      dfs(7, 0, 1, heykel))
    cout << "WIN";
  else
    cout << "LOSE";
}
