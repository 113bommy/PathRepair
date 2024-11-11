#include <bits/stdc++.h>
using namespace std;
int p[20][20];
queue<int> q;
bool findl() {
  for (int i = 0; i < 8; i++)
    if (p[i][0]) return false;
  return true;
}
int main() {
  for (int i = 7; i >= 0; i--)
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;
      if (c == 'S')
        p[i][j] = 1;
      else
        p[i][j] = 0;
    }
  if (findl()) {
    cout << "WIN";
    return 0;
  }
  q.push(0);
  q.push(0);
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    int y = q.front();
    q.pop();
    int t = q.front();
    q.pop();
    int a[20][20];
    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++) a[i][j] = p[i][j];
    if (t == 8) {
      cout << "WIN";
      return 0;
    }
    for (int jj = 0; jj < t; jj++)
      for (int j = 0; j < 8; j++)
        for (int k = 0; k < 8; k++)
          if (a[j][k]) {
            a[j][k] = 0;
            if (j - 1 >= 0) a[j - 1][k] = 1;
          }
    if (!a[x + 1][y]) {
      q.push(x);
      q.push(y);
      q.push(t + 1);
    }
    if (!a[x][y + 1] && !a[x + 1][y + 1] && y + 1 < 8) {
      q.push(x);
      q.push(y + 1);
      q.push(t + 1);
    }
    if (!a[x][y - 1] && !a[x + 1][y - 1] && y - 1 >= 0) {
      q.push(x);
      q.push(y - 1);
      q.push(t + 1);
    }
    if (!a[x + 1][y + 1] && !a[x + 2][y + 1] && y + 1 < 8) {
      q.push(x + 1);
      q.push(y + 1);
      q.push(t + 1);
    }
    if (!a[x - 1][y + 1] && !a[x][y + 1] && y + 1 < 8 && x - 1 >= 0) {
      q.push(x - 1);
      q.push(y + 1);
      q.push(t + 1);
    }
    if (!a[x - 1][y - 1] && !a[x][y - 1] && x - 1 >= 0 && y - 1 >= 0) {
      q.push(x - 1);
      q.push(y - 1);
      q.push(t + 1);
    }
    if (!a[x + 1][y - 1] && !a[x + 2][y - 1] && y - 1 >= 0) {
      q.push(x + 1);
      q.push(y - 1);
      q.push(t + 1);
    }
  }
  cout << "LOSE";
  return 0;
}
