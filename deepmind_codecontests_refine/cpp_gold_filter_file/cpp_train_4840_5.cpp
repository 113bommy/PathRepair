#include <bits/stdc++.h>
using namespace std;
long long a[200][200], n, o, p, c[200];
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
}
int main() {
  input();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 1 || a[i][j] == 3) break;
      if (j == n) o++, c[o] = i;
    }
  }
  cout << o << endl;
  for (int i = 1; i <= o; i++) {
    cout << c[i] << " ";
  }
}
