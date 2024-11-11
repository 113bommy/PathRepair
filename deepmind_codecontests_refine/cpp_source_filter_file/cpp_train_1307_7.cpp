#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000002;
const long long INFLL = 100000000000000001ll;
const long long MOD = 1000000007;
bool U[6][15];
int H, W, S[18][18], N[18][18], I1, J1, I2, J2;
unordered_map<char, int> MN, MS;
bool overlap(pair<int, int> p1, pair<int, int> p2) {
  int i1 = p1.first, j1 = p1.second;
  int i2 = p2.first, j2 = p2.second;
  bool overlap_i = (i1 <= i2 && i1 + 2 >= i2) || (i2 <= i1 && i2 + 2 >= i1);
  bool overlap_j = (j1 <= j2 && j1 + 2 >= j2) || (j2 <= j1 && j2 + 2 >= j1);
  return overlap_i && overlap_j;
}
bool ok() {
  vector<pair<int, int>> poss;
  for (int i = (1); i <= (H - 2); i++)
    for (int j = (1); j <= (W - 2); j++) {
      unordered_set<int> suits, nums;
      for (int x = (i); x <= (i + 2); x++)
        for (int y = (j); y <= (j + 2); y++) {
          suits.insert(S[x][y]);
          nums.insert(N[x][y]);
        }
      if (((int)suits.size()) == 1 || ((int)nums.size()) == 9)
        poss.push_back({i, j});
    }
  for (pair<int, int> p1 : poss)
    for (pair<int, int> p2 : poss)
      if (!overlap(p1, p2)) {
        I1 = p1.first, J1 = p1.second;
        I2 = p2.first, J2 = p2.second;
        return true;
      }
  return false;
}
string getcard(int suit, int num) {
  char s, n;
  for (pair<char, int> p : MS)
    if (p.second == suit) s = p.first;
  for (pair<char, int> p : MN)
    if (p.second == num) n = p.first;
  string ret = "";
  ret += s;
  ret += n;
  if (suit != 5) reverse(ret.begin(), ret.end());
  return ret;
}
int main() {
  MS['C'] = 1;
  MS['D'] = 2;
  MS['H'] = 3;
  MS['S'] = 4;
  MS['J'] = 5;
  MN['1'] = 0;
  MN['2'] = 1;
  MN['3'] = 2;
  MN['4'] = 3;
  MN['5'] = 4;
  MN['6'] = 5;
  MN['7'] = 6;
  MN['8'] = 7;
  MN['9'] = 8;
  MN['T'] = 9;
  MN['J'] = 10;
  MN['Q'] = 11;
  MN['K'] = 12;
  MN['A'] = 13;
  cin >> H >> W;
  int jokers = 0;
  for (int i = (1); i <= (H); i++)
    for (int j = (1); j <= (W); j++) {
      string s;
      cin >> s;
      if (s[1] == '1' || s[1] == '2') jokers++;
      if (s[1] != '1' && s[1] != '2') swap(s[0], s[1]);
      S[i][j] = MS[s[0]];
      N[i][j] = MN[s[1]];
      U[S[i][j]][N[i][j]] = true;
    }
  if (!jokers && ok()) {
    cout << "Solution exists.\n";
    cout << "There are no jokers.\n";
    cout << "Put the first square to (" << I1 << ", " << J1 << ").\n";
    cout << "Put the second square to (" << I2 << ", " << J2 << ").\n";
    return 0;
  }
  if (jokers == 1) {
    for (int i = (1); i <= (H); i++)
      for (int j = (1); j <= (W); j++) {
        if (S[i][j] == 5) {
          for (int suit = (1); suit <= (4); suit++)
            for (int num = (1); num <= (13); num++)
              if (!U[suit][num]) {
                int ps = S[i][j];
                int pn = N[i][j];
                S[i][j] = suit, N[i][j] = num;
                if (ok()) {
                  string now = getcard(ps, pn);
                  string rep = getcard(suit, num);
                  cout << "Solution exists.\n";
                  cout << "Replace " << now << " with " << rep << ".\n";
                  cout << "Put the first square to (" << I1 << ", " << J1
                       << ").\n";
                  cout << "Put the second square to (" << I2 << ", " << J2
                       << ").\n";
                  return 0;
                }
                S[i][j] = ps, N[i][j] = pn;
              }
        }
      }
  }
  if (jokers == 2) {
    for (int i1 = (1); i1 <= (H); i1++)
      for (int j1 = (1); j1 <= (W); j1++)
        if (S[i1][j1] == 5)
          for (int i2 = (1); i2 <= (H); i2++)
            for (int j2 = (1); j2 <= (W); j2++)
              if (S[i2][j2] == 5 && (i1 != i2 || j1 != j2)) {
                for (int suit1 = (1); suit1 <= (4); suit1++)
                  for (int num1 = (1); num1 <= (13); num1++)
                    if (!U[suit1][num1])
                      for (int suit2 = (1); suit2 <= (4); suit2++)
                        for (int num2 = (1); num2 <= (13); num2++)
                          if (!U[suit2][num2] &&
                              (suit1 != suit2 || num1 != num2)) {
                            int ps1 = S[i1][j1];
                            int pn1 = N[i1][j1];
                            int ps2 = S[i2][j2];
                            int pn2 = N[i2][j2];
                            S[i1][j1] = suit1, N[i1][j1] = num1;
                            S[i2][j2] = suit2, N[i1][j1] = num2;
                            if (ok()) {
                              string now1 = getcard(ps1, pn1);
                              string rep1 = getcard(suit1, num1);
                              string now2 = getcard(ps2, pn2);
                              string rep2 = getcard(suit2, num2);
                              if (now1[1] == '2')
                                swap(now1, now2), swap(rep1, rep2);
                              cout << "Solution exists.\n";
                              cout << "Replace " << now1 << " with " << rep1
                                   << " and " << now2 << " with " << rep2
                                   << ".\n";
                              cout << "Put the first square to (" << I1 << ", "
                                   << J1 << ").\n";
                              cout << "Put the second square to (" << I2 << ", "
                                   << J2 << ").\n";
                              return 0;
                            }
                            S[i1][j1] = ps1, N[i1][j1] = pn1;
                            S[i2][j2] = ps2, N[i2][j2] = pn2;
                          }
              }
  }
  cout << "No solution.";
}
