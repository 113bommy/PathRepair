#include <bits/stdc++.h>
using namespace std;
time_t start = clock();
int n, a;
char c[109][109];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int h = 0; h < n; h++) {
      cin >> c[i][h];
      if (c[i][h] == '#') a++;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int h = 1; h < n; h++) {
      if (c[i][h] == '#' && c[i - 1][h] == '#' && c[i][h + 1] == '#' &&
          c[i + 1][h] == '#' && c[i][h - 1] == '#')
        c[i][h] = '#', c[i - 1][h] = '#', c[i][h + 1] = '#', c[i + 1][h] = '#',
        c[i][h - 1] = '#', a -= 5;
    }
  }
  if (a == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
