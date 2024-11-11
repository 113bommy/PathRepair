#include <bits/stdc++.h>
using namespace std;
struct triple {
  int first;
  int second;
  int third;
  void set(int a, int b, int c) {
    first = a;
    second = b;
    third = c;
  }
};
triple t[53][53][8] = {0};
int table[53][53] = {0};
void f(int a, int b, int c) {
  if (table[a][b] == 0 || b > 50 || a > 50 || a < 1 || b < 1) return;
  int x = a;
  int y = b;
  if (c == 0) {
    while (table[x - 1][y] == table[a][b]) x--;
    while (table[x][y + 1] == table[a][b]) y++;
    if (table[x][y + 1] != 0)
      t[a][b][c].set(x, y + 1, c);
    else
      t[a][b][c].set(a, b, 1);
  } else if (c == 1) {
    while (table[x + 1][y] == table[a][b]) x++;
    while (table[x][y + 1] == table[a][b]) y++;
    if (table[x][y + 1] != 0)
      t[a][b][c].set(x, y + 1, c);
    else
      t[a][b][c].set(a, b, 2);
  } else if (c == 2) {
    while (table[x + 1][y] == table[a][b]) x++;
    while (table[x][y + 1] == table[a][b]) y++;
    if (table[x + 1][y] != 0)
      t[a][b][c].set(x + 1, y, c);
    else
      t[a][b][c].set(a, b, 3);
  } else if (c == 3) {
    while (table[x + 1][y] == table[a][b]) x++;
    while (table[x][y - 1] == table[a][b]) y--;
    if (table[x + 1][y] != 0)
      t[a][b][c].set(x + 1, y, c);
    else
      t[a][b][c].set(a, b, 4);
  } else if (c == 4) {
    while (table[x + 1][y] == table[a][b]) x++;
    while (table[x][y - 1] == table[a][b]) y--;
    if (table[x][y - 1] != 0)
      t[a][b][c].set(x, y - 1, c);
    else
      t[a][b][c].set(a, b, 5);
  } else if (c == 5) {
    while (table[x - 1][y] == table[a][b]) x--;
    while (table[x][y - 1] == table[a][b]) y--;
    if (table[x][y - 1] != 0)
      t[a][b][c].set(x, y - 1, c);
    else
      t[a][b][c].set(a, b, 6);
  } else if (c == 6) {
    while (table[x + 1][y] == table[a][b]) x--;
    while (table[x][y - 1] == table[a][b]) y--;
    if (table[x - 1][y] != 0)
      t[a][b][c].set(x - 1, y, c);
    else
      t[a][b][c].set(a, b, 7);
  } else if (c == 7) {
    while (table[x - 1][y] == table[a][b]) x--;
    while (table[x][y + 1] == table[a][b]) y++;
    if (table[x - 1][y] != 0)
      t[a][b][c].set(x - 1, y, c);
    else
      t[a][b][c].set(a, b, 0);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  int h = 0;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (int j = 0; j < s.size(); j++) {
      table[i + 1][j + 1] = s[j] - '0';
    }
  }
  h = s.size();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= h; j++) {
      for (int k = 0; k < 8; k++) {
        f(i, j, k);
      }
    }
  }
  int q1 = 1, q2 = 1, q3 = 0;
  int w1, w2, w3;
  for (int i = 0; i < m; i++) {
    w1 = t[q1][q2][q3].first;
    w2 = t[q1][q2][q3].second;
    w3 = t[q1][q2][q3].third;
    q1 = w1;
    q2 = w2;
    q3 = w3;
  }
  cout << table[q1][q2] << endl;
}
