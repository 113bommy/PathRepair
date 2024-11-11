#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > A(4, vector<int>(3, 0));
void score(string s, int a, int b) {
  int sa = s[0] - '0';
  int sb = s[2] - '0';
  if (sa == sb) {
    A[a][0]++;
    A[a][2] += sa;
    A[b][0]++;
    A[b][2] += sb;
    return;
  }
  if (sa > sb) {
    A[a][0] += 3;
    A[a][1] += sa - sb;
    A[a][2] += sa;
    A[b][1] += sb - sa;
    A[b][2] += sb;
    return;
  }
  A[b][0] += 3;
  A[b][1] += sb - sa;
  A[b][2] += sb;
  A[a][1] += sa - sb;
  A[a][2] += sa;
}
void score(int sa, int sb, int a, int b) {
  if (sa == sb) {
    A[a][0]++;
    A[a][2] += sa;
    A[b][0]++;
    A[b][2] += sb;
    return;
  }
  if (sa > sb) {
    A[a][0] += 3;
    A[a][1] += sa - sb;
    A[a][2] += sa;
    A[b][1] += sb - sa;
    A[b][2] += sb;
    return;
  }
  A[b][0] += 3;
  A[b][1] += sb - sa;
  A[b][2] += sb;
  A[a][1] += sa - sb;
  A[a][2] += sa;
}
int main() {
  string s1, s2, s3;
  string my = "BERLAND";
  string opp = "";
  map<string, int> M;
  vector<int> games(4, 3);
  vector<string> names;
  for (int i = (0); i < (5); ++i) {
    cin >> s1 >> s2 >> s3;
    if (M.find(s1) == M.end()) {
      M[s1] = int((M).size());
      names.push_back(s1);
    }
    if (M.find(s2) == M.end()) {
      M[s2] = int((M).size());
      names.push_back(s2);
    }
    int a = M[s1];
    int b = M[s2];
    score(s3, a, b);
    games[a]--;
    games[b]--;
  }
  vector<int> players;
  for (int i = (0); i < (4); ++i) {
    if (games[i]) players.push_back(i);
  }
  int my_idx = M[my];
  int p1 = players[0];
  int p2 = players[1];
  if (p1 != my_idx) swap(p1, p2);
  vector<vector<int> > save = A;
  pair<int, int> res = make_pair((2000000000), 0);
  for (int i = (0); i < (100); ++i) {
    for (int j = (0); j < (100); ++j) {
      A = save;
      if (i <= j) continue;
      score(i, j, p1, p2);
      int worse = 0;
      for (int k = (0); k < (4); ++k) {
        if (k == p1) continue;
        if (A[k] == A[p1]) {
          if (names[p1] < names[k]) worse++;
          continue;
        }
        if (A[k][0] < A[p1][0] ||
            (A[k][0] == A[p1][0] &&
             (A[k][1] < A[p1][1] ||
              (A[k][1] == A[p1][1] && A[k][2] < A[p1][2]))))
          worse++;
      }
      if (worse > 1) {
        int diff = i - j;
        if (diff < res.first - res.second ||
            (diff == res.first - res.second && res.second > j))
          res = make_pair(i, j);
      }
    }
  }
  if (res == make_pair((2000000000), 0))
    cout << "IMPOSSIBLE\n";
  else
    cout << res.first << ":" << res.second << endl;
  return 0;
}
