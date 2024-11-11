#include <bits/stdc++.h>
using namespace std;
pair<int, int> dirs[] = {{1, 2},  {-1, 2},  {2, 1},  {2, -1},
                         {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};
const int N = 1e5 + 7;
bool cmp(vector<int> a, vector<int> b) { return a.size() < b.size(); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n;
  long long k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> moves;
  long long maxMoves = 0;
  vector<int> v;
  for (int k = 0; k <= n * n; k++) {
    v.clear();
    for (int i = 0; i < (int)s.size() - 1; i++) {
      if (s[i] == 'R' && s[i + 1] == 'L') v.push_back(i);
    }
    if (v.empty()) break;
    for (auto i : v) {
      s[i] = 'L';
      s[i + 1] = 'R';
    }
    moves.push_back(v);
    maxMoves += v.size();
  }
  if (moves.size() > k || maxMoves < k) {
    cout << -1;
    return 0;
  }
  int curr = 0;
  vector<vector<int>> newMoves;
  int moveCount = moves.size();
  while (curr < moves.size()) {
    while (moveCount < k && moves[curr].size() > 1) {
      newMoves.push_back({moves[curr].back()});
      moves[curr].pop_back();
      moveCount++;
    }
    newMoves.push_back(moves[curr]);
    curr++;
  }
  for (auto& i : newMoves) {
    cout << i.size() << " ";
    for (auto j : i) {
      cout << j + 1 << " ";
    }
    cout << '\n';
  }
}
