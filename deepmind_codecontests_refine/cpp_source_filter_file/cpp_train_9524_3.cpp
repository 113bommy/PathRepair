#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "{";
  for (const T &a : v) out << a << ", ";
  out << "}";
  return out;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}
int n;
char board[53][53];
char result[103][103];
void umark(int dx, int dy) { result[n - 1 + dx][n - 1 + dy] = '.'; }
bool possible(int dx, int dy) { return result[n - 1 + dx][n - 1 + dy] == 'x'; }
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%s", board[i]);
  for (int i = (0); i < (2 * n - 1); ++i)
    for (int j = (0); j < (2 * n - 1); ++j) result[i][j] = 'x';
  result[n - 1][n - 1] = 'o';
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j)
      if (board[i][j] == 'o')
        for (int di = (-i); di < (n - i); ++di)
          for (int dj = (-j); dj < (n - 1); ++dj)
            if (board[i + di][j + dj] == '.') umark(di, dj);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j)
      if (board[i][j] == 'o')
        for (int di = (-i); di < (n - i); ++di)
          for (int dj = (-j); dj < (n - 1); ++dj)
            if (possible(di, dj) && board[i + di][j + dj] == 'x')
              board[i + di][j + dj] = '.';
  bool works = 1;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j)
      if (board[i][j] == 'x') works = 0;
  if (works) {
    printf("YES\n");
    for (int i = (0); i < (2 * n - 1); ++i) {
      for (int j = (0); j < (2 * n - 1); ++j) printf("%c", result[i][j]);
      printf("\n");
    }
  } else
    printf("NO\n");
  return 0;
}
