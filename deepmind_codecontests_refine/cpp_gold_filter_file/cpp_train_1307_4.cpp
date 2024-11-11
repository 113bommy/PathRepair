#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<char, char>>> desk;
struct joker {
  int i;
  int j;
  joker() {
    i = -1;
    j = -1;
  }
};
struct sqrNormal {
  int i;
  int j;
  sqrNormal() {
    i = -1;
    j = -1;
  }
};
sqrNormal sqr1, sqr2;
vector<pair<char, char>> genCards() {
  vector<pair<char, char>> cards;
  char mastChar[] = {'C', 'D', 'H', 'S'};
  vector<char> mast(mastChar, mastChar + sizeof(mastChar) / sizeof(char));
  char numberChar[] = {'2', '3', '4', '5', '6', '7', '8',
                       '9', 'T', 'J', 'Q', 'K', 'A'};
  vector<char> number(numberChar,
                      numberChar + sizeof(numberChar) / sizeof(char));
  for (int i = 0; i < mast.size(); i++) {
    for (int j = 0; j < number.size(); j++) {
      cards.push_back(make_pair(number[j], mast[i]));
    }
  }
  return cards;
}
vector<pair<char, char>> findFreeCards(vector<pair<char, char>> cards) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (desk[i][j] == make_pair('J', '1') ||
          desk[i][j] == make_pair('J', '2'))
        continue;
      cards.erase(find(cards.begin(), cards.end(), desk[i][j]));
    }
  }
  return cards;
}
void findJoker(joker &j1, joker &j2) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (desk[i][j] == make_pair('J', '1')) {
        j1.i = i;
        j1.j = j;
      }
      if (desk[i][j] == make_pair('J', '2')) {
        j2.i = i;
        j2.j = j;
      }
    }
  }
}
bool isNormalSqrMast(int x, int y) {
  if (x + 3 > n || y + 3 > m) return false;
  char mast = desk[x][y].second;
  bool flag = true;
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (!(mast == desk[i][j].second)) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }
  return flag;
}
bool isNormalSqrNumber(int x, int y) {
  if (x + 3 > n || y + 3 > m) return false;
  char numberChar[] = {'2', '3', '4', '5', '6', '7', '8',
                       '9', 'T', 'J', 'Q', 'K', 'A'};
  vector<char> number(numberChar,
                      numberChar + sizeof(numberChar) / sizeof(char));
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (find(number.begin(), number.end(), desk[i][j].first) != number.end())
        number.erase(find(number.begin(), number.end(), desk[i][j].first));
      else
        return false;
    }
  }
  return true;
}
bool isNormalDesk() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isNormalSqrMast(i, j) || isNormalSqrNumber(i, j)) {
        for (int ii = 0; ii < n; ii++) {
          for (int jj = 0; jj < m; jj++) {
            if (ii == i && jj == j) continue;
            if (abs(i - ii) < 3 && abs(j - jj) < 3) continue;
            if (isNormalSqrMast(ii, jj) || isNormalSqrNumber(ii, jj)) {
              sqr1.i = i;
              sqr1.j = j;
              sqr2.i = ii;
              sqr2.j = jj;
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vector<pair<char, char>> stroka;
    for (int j = 0; j < m; j++) {
      char mast, number;
      cin >> mast >> number;
      stroka.push_back(make_pair(mast, number));
    }
    desk.push_back(stroka);
  }
  vector<pair<char, char>> cards = genCards();
  vector<pair<char, char>> freeCards = findFreeCards(cards);
  joker j1, j2;
  findJoker(j1, j2);
  char numberjoker1;
  char numberjoker2;
  if (j1.i != -1 && j1.j != -1) numberjoker1 = desk[j1.i][j1.j].second;
  if (j2.i != -1 && j2.j != -1) numberjoker2 = desk[j2.i][j2.j].second;
  for (int i = 0; i < freeCards.size(); i++) {
    if (j1.i != -1 && j1.j != -1) {
      desk[j1.i][j1.j] = freeCards[i];
    }
    for (int j = 0; j < freeCards.size(); j++) {
      if (i == j) continue;
      if (j2.i != -1 && j2.j != -1) {
        desk[j2.i][j2.j] = freeCards[j];
      }
      if (isNormalDesk()) {
        cout << "Solution exists." << endl;
        if (j1.i == -1 && j1.j == -1 && j2.i == -1 && j2.j == -1)
          cout << "There are no jokers." << endl;
        else if (j2.i == -1 && j2.j == -1)
          cout << "Replace J" << numberjoker1 << " with " << freeCards[i].first
               << freeCards[i].second << "." << endl;
        else if (j1.i == -1 && j1.j == -1)
          cout << "Replace J" << numberjoker2 << " with " << freeCards[j].first
               << freeCards[j].second << "." << endl;
        else {
          cout << "Replace J1";
          if (numberjoker1 == '1')
            cout << " with " << freeCards[i].first << freeCards[i].second
                 << " and J2 with " << freeCards[j].first << freeCards[j].second
                 << "." << endl;
          else
            cout << " with " << freeCards[j].first << freeCards[j].second
                 << " and J2 with " << freeCards[i].first << freeCards[i].second
                 << "." << endl;
        }
        cout << "Put the first square to (" << sqr1.i + 1 << ", " << sqr1.j + 1
             << ")." << endl;
        cout << "Put the second square to (" << sqr2.i + 1 << ", " << sqr2.j + 1
             << ")." << endl;
        return 0;
      }
    }
  }
  cout << "No solution." << endl;
  return 0;
}
