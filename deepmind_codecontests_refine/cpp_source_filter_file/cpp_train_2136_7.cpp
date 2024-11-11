#include <bits/stdc++.h>
using namespace std;
int tab[2000000];
char s[2000000];
int N;
char path[1000000];
void kmp() {
  tab[0] = 0;
  int i, y;
  for (i = 0; i < N - 1; i++) {
    y = tab[i];
    while (y > 0 && s[y] != s[i + 1]) y = tab[y - 1];
    if (s[i + 1] == s[y]) tab[i + 1] = y + 1;
  }
}
int main() {
  int n, i;
  cin >> n;
  scanf("%s", path);
  map<char, char> opposite = {{'N', 'S'}, {'E', 'W'}, {'S', 'N'}, {'W', 'E'}};
  for (i = 0; i < n - 1; i++) s[i] = opposite[path[n - 2]];
  s[n - 1] = '$';
  scanf("%s", s + n);
  N = 2 * n - 1;
  memset(tab, 0, sizeof(tab));
  kmp();
  if (tab[N - 1] == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
