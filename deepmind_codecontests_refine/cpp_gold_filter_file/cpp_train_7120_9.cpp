#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > Rec(26);
int checkpalin(vector<char> V) {
  int i, n = V.size();
  for (i = 0; i < n / 2; i++) {
    if (V[i] != V[n - 1 - i]) {
      return 0;
    }
  }
  return 1;
}
int Row[101], Col[101], A[107];
string s1, s2;
struct sort_pred {
  bool operator()(const std::pair<int, int> &left,
                  const std::pair<int, int> &right) {
    return left.second < right.second;
  }
};
int main() {
  int r, c, i, j, Ans = 0, ctr;
  cin >> c;
  r = c;
  char str[r][c + 1];
  for (i = 0; i < r; i++) {
    scanf("%s", &str[i]);
  }
  memset(Row, 0, sizeof Row);
  memset(Col, 0, sizeof Col);
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (str[i][j] == '.') {
        Col[j] = 1;
        Row[i] = 1;
      }
    }
  }
  int ctr1 = 0, ctr2 = 0;
  for (i = 0; i < r; i++) {
    if (Row[i]) ctr1++;
    if (Col[i]) ctr2++;
  }
  if (ctr1 == r) {
    for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
        if (str[i][j] == '.') {
          printf("%d %d\n", i + 1, j + 1);
          break;
        }
      }
    }
  } else if (ctr2 == r) {
    for (i = 0; i < c; i++) {
      for (j = 0; j < r; j++) {
        if (str[j][i] == '.') {
          printf("%d %d\n", j + 1, i + 1);
          break;
        }
      }
    }
  } else {
    cout << "-1\n";
  }
  return 0;
}
