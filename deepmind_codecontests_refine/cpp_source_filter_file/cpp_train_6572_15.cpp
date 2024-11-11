#include <bits/stdc++.h>
char s[510][510];
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  int c = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < n; j++) {
      if (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' &&
          s[i + 1][j - 1] == 'X' && s[i + 1][j + 1])
        c++;
    }
  }
  cout << c << endl;
  return 0;
}
