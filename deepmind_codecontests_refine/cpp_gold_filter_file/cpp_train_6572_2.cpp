#include <bits/stdc++.h>
using namespace std;
int N, counter;
char a[(int)500 + 2][(int)500 + 2];
bool check(int i, int j) {
  return (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j + 1] &&
          a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 1][j + 1] &&
          a[i][j] == 'X');
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> a[i][j];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (check(i, j)) counter++;
    }
  }
  cout << counter;
  return 0;
}
