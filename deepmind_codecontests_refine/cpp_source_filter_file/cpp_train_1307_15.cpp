#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 52 + 7;
pair<char, char> a[N][N];
map<pair<char, char>, int> c;
int n, m;
pair<int, int> w1, w2;
bool check() {
  vector<pair<int, int> > vec;
  for (int i = 0; i <= n - 3; i++)
    for (int j = 0; j <= m - 3; j++) {
      set<char> st;
      bool oks = 1;
      char suit = a[i][j].second;
      for (int ki = 0; ki <= 2; ki++)
        for (int kj = 0; kj <= 2; kj++) {
          st.insert(a[i + ki][j + kj].first);
          if (suit != a[i + ki][j + kj].second) oks = 0;
        }
      if (oks || st.size() == 9) vec.push_back({i, j});
    }
  int sz = vec.size();
  for (int i = 0; i <= sz - 1; i++)
    for (int j = 0; j <= sz - 1; j++) {
      if (i == j) continue;
      if (vec[j].first + 2 < vec[i].first ||
          vec[j].second + 2 < vec[i].second) {
        w1 = vec[i];
        w2 = vec[j];
        return 1;
      } else if (vec[j].first > vec[i].first + 2 ||
                 vec[j].second > vec[i].second + 2) {
        w1 = vec[i];
        w2 = vec[j];
        return 1;
      }
    }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string r = "23456789JTKA";
  string s = "CDHS";
  cin >> n >> m;
  int J1i = -1, J1j = -1, J2i = -1, J2j = -1;
  for (int i = 0; i <= n - 1; i++)
    for (int j = 0; j <= m - 1; j++) {
      cin >> a[i][j].first >> a[i][j].second;
      if (a[i][j].first == 'J') {
        if (a[i][j].second == '1') {
          J1i = i;
          J1j = j;
        } else if (a[i][j].second == '2') {
          J2i = i;
          J2j = j;
        }
      }
      c[a[i][j]]++;
    }
  if (J1i != -1 && J2i != -1) {
    for (int i1 = 0; i1 <= 11; i1++)
      for (int j1 = 0; j1 <= 3; j1++) {
        if (c[{r[i1], s[j1]}] > 0) continue;
        c[{r[i1], s[j1]}]++;
        a[J1i][J1j] = {r[i1], s[j1]};
        for (int i2 = 0; i2 <= 10; i2++)
          for (int j2 = 0; j2 <= 3; j2++) {
            if (c[{r[i2], s[j2]}] > 0) continue;
            c[{r[i2], s[j2]}]++;
            a[J2i][J2j] = {r[i2], s[j2]};
            if (check()) {
              cout << "Solution exists." << endl;
              cout << "Replace J1 with " << r[i1] << s[j1] << " and J2 with "
                   << r[i2] << s[j2] << "." << endl;
              cout << "Put the first square to (" << w1.first + 1 << ", "
                   << w1.second + 1 << ")." << endl;
              cout << "Put the second square to (" << w2.first + 1 << ", "
                   << w2.second + 1 << ")." << endl;
              return 0;
            }
            a[J2i][J2j] = {'J', '2'};
            c[{r[i2], s[j2]}]--;
          }
        a[J1i][J1j] = {'J', '1'};
        c[{r[i1], s[j1]}]--;
      }
  } else if (J1i != -1) {
    for (int i1 = 0; i1 <= 11; i1++)
      for (int j1 = 0; j1 <= 3; j1++) {
        if (c[{r[i1], s[j1]}] > 0) continue;
        c[{r[i1], s[j1]}]++;
        a[J1i][J1j] = {r[i1], s[j1]};
        if (check()) {
          cout << "Solution exists." << endl;
          cout << "Replace J1 with " << r[i1] << s[j1] << "." << endl;
          cout << "Put the first square to (" << w1.first + 1 << ", "
               << w1.second + 1 << ")." << endl;
          cout << "Put the second square to (" << w2.first + 1 << ", "
               << w2.second + 1 << ")." << endl;
          return 0;
        }
        a[J1i][J1j] = {'J', '2'};
        c[{r[i1], s[j1]}]--;
      }
  } else if (J2i != -1) {
    for (int i2 = 0; i2 <= 11; i2++)
      for (int j2 = 0; j2 <= 3; j2++) {
        if (c[{r[i2], s[j2]}] > 0) continue;
        c[{r[i2], s[j2]}]++;
        a[J2i][J2j] = {r[i2], s[j2]};
        if (check()) {
          cout << "Solution exists." << endl;
          cout << "Replace J2 with " << r[i2] << s[j2] << "." << endl;
          cout << "Put the first square to (" << w1.first + 1 << ", "
               << w1.second + 1 << ")." << endl;
          cout << "Put the second square to (" << w2.first + 1 << ", "
               << w2.second + 1 << ")." << endl;
          return 0;
        }
        a[J2i][J2j] = {'J', '2'};
        c[{r[i2], s[j2]}]--;
      }
  } else if (check()) {
    cout << "Solution exists." << endl;
    cout << "There are no jokers." << endl;
    cout << "Put the first square to (" << w1.first + 1 << ", " << w1.second + 1
         << ")." << endl;
    cout << "Put the second square to (" << w2.first + 1 << ", "
         << w2.second + 1 << ")." << endl;
    return 0;
  }
  cout << "No solution." << endl;
  return 0;
}
