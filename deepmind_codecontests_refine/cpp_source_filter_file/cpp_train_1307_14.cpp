#include <bits/stdc++.h>
int faster_in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -faster_in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
using namespace std;
const int INF = 1234567890;
string M[20][20];
string ranks = "23456789TJQKA";
string suits = "CDHS";
set<string> cards;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  for (char c : ranks) {
    for (char s : suits) {
      string tmp = "";
      tmp += c;
      tmp += s;
      cards.insert(tmp);
    }
  }
  pair<int, int> joker[2] = {{19, 19}, {19, 19}};
  int n, m;
  cin >> n >> m;
  for (int i = (int)0; i < (int)n; ++i) {
    for (int j = (int)0; j < (int)m; ++j) {
      cin >> M[i][j];
      if (M[i][j][1] == '1') {
        joker[0] = {i, j};
      } else if (M[i][j][1] == '2') {
        joker[1] = {i, j};
      } else {
        cards.erase(M[i][j]);
      }
    }
  }
  vector<string> sobra;
  for (string x : cards) {
    sobra.push_back(x);
  }
  for (int ite1 = (int)0; ite1 < (int)sobra.size(); ++ite1) {
    for (int ite2 = (int)0; ite2 < (int)sobra.size(); ++ite2) {
      if (ite1 == ite2) break;
      M[joker[0].first][joker[0].second] = sobra[ite1];
      M[joker[1].first][joker[1].second] = sobra[ite2];
      vector<pair<int, int> > posibles;
      for (int i = (int)0; i < (int)n; ++i) {
        for (int j = (int)0; j < (int)m; ++j) {
          set<char> rank;
          for (int k = (int)i; k < (int)i + 3; ++k) {
            for (int l = (int)j; l < (int)j + 3; ++l) {
              if (k >= n || l >= m) break;
              rank.insert(M[k][l][0]);
            }
          }
          if (rank.size() == 9) posibles.push_back({i, j});
        }
      }
      for (pair<int, int> p1 : posibles) {
        for (pair<int, int> p2 : posibles) {
          if (p1 == p2) continue;
          if (abs(p1.first - p2.first) >= 3 ||
              abs(p1.second - p2.second) >= 3) {
            cout << "Solution exists." << '\n';
            int jokrs = (joker[0].first < n) + (joker[1].first < n);
            if (jokrs == 0)
              cout << "There are no jokers." << '\n';
            else if (jokrs == 1)
              cout << "Replace J" << (joker[0].first < n ? 1 : 2) << " with "
                   << (joker[0].first < n ? sobra[ite1] : sobra[ite2]) << ".\n";
            else
              cout << "Replace J1 with " << sobra[ite1] << " and J2 with "
                   << sobra[ite2] << ".\n";
            cout << "Put the first square to (" << p1.first + 1 << ", "
                 << p1.second + 1 << ")." << '\n';
            cout << "Put the second square to (" << p2.first + 1 << ", "
                 << p2.second + 1 << ")." << '\n';
            return 0;
          }
        }
      }
    }
  }
  cout << "No solution." << '\n';
  return 0;
}
