#include <bits/stdc++.h>
const int nmax = 1e3 + 5;
std::string s[2 * nmax], aux[2 * nmax];
bool m[nmax][nmax];
int h, w, k, tot;
void solve(int row) {
  m[row][1] = 0;
  for (int i = 2; i <= w; i++)
    if (s[2 * row - 1][i - 2] == 'N')
      m[row][i] = 1 - m[row][i - 1];
    else
      m[row][i] = m[row][i - 1];
}
void invert(int row) {
  for (int i = 1; i <= w; i++) m[row][i] = 1 - m[row][i];
}
void check(int row) {
  solve(row);
  int right = 0;
  for (int i = 1; i <= w; i++)
    if ((m[row][i] == m[row - 1][i]) == (s[2 * row - 2][i - 1] == 'E')) right++;
  if (right <= w / 2) invert(row);
}
int main() {
  bool swapped = false;
  std::cin >> h >> w >> k;
  for (int i = 1; i < 2 * h; i++) std::cin >> aux[i], tot += (int)aux[i].size();
  if (k == 1) {
    int nr = 0;
    for (int i = 1; i < 2 * h; i++)
      for (auto x : aux[i]) nr += (x == 'E');
    if (nr * 4 < tot * 3)
      std::cout << "NO";
    else {
      std::cout << "YES\n";
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) std::cout << "1 ";
        std::cout << "\n";
      }
    }
    return 0;
  }
  if (w >= h)
    for (int i = 1; i < 2 * h; i++) s[i] = aux[i];
  else {
    for (int i = 1; i < 2 * h; i++) {
      if (i % 2)
        for (int j = 2; j < 2 * h; j += 2) s[i] += aux[j][i / 2];
      else
        for (int j = 1; j < 2 * h; j += 2) s[i] += aux[j][i / 2 - 1];
      std::reverse(s[i].begin(), s[i].end());
    }
    std::swap(w, h), swapped = true;
  }
  solve(1);
  for (int row = 2; row <= h; row++) check(row);
  std::cout << "YES\n";
  if (swapped == false)
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) std::cout << m[i][j] + 1 << " ";
      std::cout << "\n";
    }
  else
    for (int i = 1; i <= w; i++) {
      for (int j = 1; j <= h; j++) std::cout << m[j][i] + 1 << " ";
      std::cout << "\n";
    }
}
