#include <bits/stdc++.h>
using namespace std;
void swapRY(int a[2]) { swap(a[0], a[1]); }
void swapRB(int a[2]) { a[1] ^= a[0]; }
void swapYB(int a[2]) { a[0] ^= a[1]; }
int id(char c) {
  if (c == 'W') return 0;
  if (c == 'R') return 1;
  if (c == 'Y') return 2;
  if (c == 'B') return 3;
  assert(0);
  return -1;
}
bitset<2001> a[3000];
bool solve(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (a[j][i]) {
        swap(a[i], a[j]);
        break;
      }
    if (!a[i][i]) {
      swap(a[i], a[m++]);
      a[i][i] = 1;
    }
    for (int j = 0; j < m; j++)
      if (j != i && a[j][i]) {
        a[j] ^= a[i];
      }
  }
  for (int i = n; i < m; i++)
    if (a[i][n]) return false;
  return true;
}
int b[2000][2];
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) b[i][0] = 1, b[i][1] = 2;
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    string op;
    cin >> op;
    if (op == "mix") {
      int m;
      cin >> m;
      while (m--) {
        int j;
        cin >> j;
        j--;
        a[cnt][j] = b[j][0] & 1, a[cnt][j + n] = b[j][0] >> 1 & 1;
        a[cnt + 1][j] = b[j][1] & 1, a[cnt + 1][j + n] = b[j][1] >> 1 & 1;
      }
      char c;
      cin >> c;
      int r = id(c);
      a[cnt][2 * n] = r & 1;
      a[cnt + 1][2 * n] = r >> 1 & 1;
      cnt += 2;
    }
    if (op == "RY") {
      int m;
      for (cin >> m; m; m--) {
        int j;
        cin >> j;
        j--;
        swapRY(b[j]);
      }
    }
    if (op == "RB") {
      int m;
      for (cin >> m; m; m--) {
        int j;
        cin >> j;
        j--;
        swapRB(b[j]);
      }
    }
    if (op == "YB") {
      int m;
      for (cin >> m; m; m--) {
        int j;
        cin >> j;
        j--;
        swapYB(b[j]);
      }
    }
  }
  if (!solve(2 * n, cnt))
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      int x = a[i][2 * n] + 2 * a[i + n][2 * n];
      cout << (".RYB"[x]);
    }
    cout << endl;
  }
}
