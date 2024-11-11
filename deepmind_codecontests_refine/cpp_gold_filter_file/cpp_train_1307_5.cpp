#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> joker[2] = {{-1, -1}, {-1, -1}};
pair<int, int> s1 = {-1, -1}, s2 = {-1, -1};
string ranks = "23456789TJQKA", suits = "CDHS", a[64][64];
set<string> deck;
vector<string> left_cards;
void gen_deck() {
  for (char r : ranks)
    for (char s : suits) {
      string res = "";
      res = res + r;
      res = res + s;
      deck.insert(res);
    }
}
bool can(int ii, int jj) {
  set<char> cur_ranks;
  set<char> cur_suits;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      cur_ranks.insert(a[ii + i][jj + j][0]);
      cur_suits.insert(a[ii + i][jj + j][1]);
    }
  return ((((int)(cur_ranks).size()) == 9) || (((int)(cur_suits).size()) == 1));
}
bool check() {
  for (int lr = 0; lr < n - 2; lr++)
    for (int lc = 0; lc < m - 2; lc++)
      for (int rr = 0; rr < n - 2; rr++)
        for (int rc = 0; rc < m - 2; rc++) {
          if (rr < lr + 3 && rc < lc + 3) continue;
          if (can(lr, lc) && can(rr, rc)) {
            s1 = {lr, lc};
            s2 = {rr, rc};
            return 1;
          }
        }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  gen_deck();
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j][0] == 'J') joker[a[i][j][1] - '1'] = {i, j};
      deck.erase(a[i][j]);
    }
  for (auto it : deck) left_cards.push_back(it);
  for (int i = 0; i < ((int)(left_cards).size()); i++)
    for (int j = 0; j < ((int)(left_cards).size()); j++) {
      if (i == j) continue;
      if (joker[0].first != -1)
        a[joker[0].first][joker[0].second] = left_cards[i];
      if (joker[1].first != -1)
        a[joker[1].first][joker[1].second] = left_cards[j];
      if (check()) {
        cout << "Solution exists." << endl;
        if (joker[0].first < 0 && joker[1].first < 0) {
          cout << "There are no jokers." << endl;
        } else if (!((joker[0].first < 0) || (joker[1].first < 0))) {
          cout << "Replace J1 with " << left_cards[i] << " and J2 with "
               << left_cards[j] << "." << endl;
        } else {
          if (joker[0].first < 0) {
            cout << "Replace J2 with " << left_cards[j] << "." << endl;
          } else {
            cout << "Replace J1 with " << left_cards[i] << "." << endl;
          }
        }
        cout << "Put the first square to (" << s1.first + 1 << ", "
             << s1.second + 1 << ")." << endl;
        cout << "Put the second square to (" << s2.first + 1 << ", "
             << s2.second + 1 << ")." << endl;
        return 0;
      }
    }
  cout << "No solution." << endl;
}
