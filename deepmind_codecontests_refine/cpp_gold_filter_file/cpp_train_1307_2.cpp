#include <bits/stdc++.h>
using namespace std;
string a[50][50];
int n, m;
set<string> temp;
int cnt;
pair<int, int> square1, square2;
bool check() {
  for (int z = 0; z < n; z++) {
    for (int k = 0; k < m; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (abs(z - i) < 3 && abs(k - j) < 3) {
            continue;
          }
          if ((i + 2) > n - 1 || (z + 2) > n - 1 || abs(j + 2) > m - 1 ||
              (k + 2) > m - 1) {
            continue;
          }
          set<char> rank1, suit1, rank2, suit2;
          for (int y = i; y <= i + 2; y++) {
            for (int l = j; l <= j + 2; l++) {
              string x = a[y][l];
              rank1.insert(x[0]);
              suit1.insert(x[1]);
            }
          }
          for (int y = z; y <= z + 2; y++) {
            for (int l = k; l <= k + 2; l++) {
              string x = a[y][l];
              rank2.insert(x[0]);
              suit2.insert(x[1]);
            }
          }
          if (((int)rank1.size() == 9 || (int)suit1.size() == 1) &&
              ((int)rank2.size() == 9 || (int)suit2.size() == 1)) {
            square1.first = i + 1;
            square1.second = j + 1;
            square2.first = z + 1;
            square2.second = k + 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}
int main() {
  string ranks[] = {"2", "3", "4", "5", "6", "7", "8",
                    "9", "T", "J", "Q", "K", "A"};
  string suits[] = {"C", "D", "H", "S"};
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      string x = ranks[i] + suits[j];
      temp.insert(x);
    }
  }
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == "J1" || a[i][j] == "J2") {
        cnt++;
      } else {
        temp.erase(a[i][j]);
      }
    }
  }
  vector<string> table;
  for (auto it = temp.begin(); it != temp.end(); it++) {
    table.push_back(*it);
  }
  string j1, j2;
  for (int z = 0; z < (int)table.size(); z++) {
    for (int k = 0; k < (int)table.size(); k++) {
      if (z == k) continue;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] == "J1") {
            a[i][j] = table[z];
            j1 = table[z];
          }
          if (a[i][j] == "J2") {
            a[i][j] = table[k];
            j2 = table[k];
          }
        }
      }
      if (check()) {
        cout << "Solution exists." << endl;
        if (j1 != "" && j2 != "") {
          cout << "Replace J1 with " << j1 << " and J2 with " << j2 << "."
               << endl;
        }
        if (j1 != "" && j2 == "") {
          cout << "Replace J1 with " << j1 << "." << endl;
        }
        if (j2 != "" && j1 == "") {
          cout << "Replace J2 with " << j2 << "." << endl;
        }
        if (j1 == "" && j2 == "") {
          cout << "There are no jokers." << endl;
        }
        cout << "Put the first square to (" << square1.first << ", "
             << square1.second << ")." << endl;
        cout << "Put the second square to (" << square2.first << ", "
             << square2.second << ")." << endl;
        return 0;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] == j1) {
            a[i][j] = "J1";
          }
          if (a[i][j] == j2) {
            a[i][j] = "J2";
          }
        }
      }
    }
  }
  cout << "No solution.";
  return 0;
}
