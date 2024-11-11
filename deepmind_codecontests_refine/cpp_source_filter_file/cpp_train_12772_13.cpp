#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int A, B, C, D;
int n, m;
char tab[N][N];
void solve_AB() {
  B--;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 25; j++) {
      tab[i][j] = 'B';
    }
  }
  for (int i = 1; i <= n; i++) {
    tab[i][25] = 'A';
  }
  for (int i = 2; i <= n && B; i += 2) {
    for (int j = 1; j <= 25; j++) {
      tab[i][j] = 'A';
    }
    B--;
    for (int j = 23; j >= 1 && B; j -= 2) {
      tab[i - 1][j] = 'A';
      B--;
    }
  }
  A--;
  for (int i = 50; i >= 1 && A; i -= 2) {
    for (int j = 1; j <= 23 && A; j += 2) {
      tab[i][j] = 'A';
      A--;
    }
  }
}
void solve_CD() {
  D--;
  for (int i = 1; i <= n; i++) {
    for (int j = 26; j <= m; j++) {
      tab[i][j] = 'D';
    }
  }
  for (int i = 1; i <= n; i++) {
    tab[i][26] = 'C';
  }
  for (int i = 2; i <= n && D; i += 2) {
    for (int j = 26; j <= m; j++) {
      tab[i][j] = 'C';
    }
    D--;
    for (int j = 28; j <= 50 && D; j += 2) {
      tab[i - 1][j] = 'C';
      D--;
    }
  }
  C--;
  for (int i = 50; i >= 1 && C; i -= 2) {
    for (int j = 28; j <= 50 && C; j += 2) {
      tab[i][j] = 'C';
      C--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> A >> B >> C >> D;
  n = m = 50;
  solve_AB();
  solve_CD();
  cout << n << " " << m << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << tab[i][j];
    }
    cout << endl;
  }
  return 0;
}
