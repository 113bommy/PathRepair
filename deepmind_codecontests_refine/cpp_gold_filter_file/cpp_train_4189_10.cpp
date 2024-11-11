#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int i, j, k, l, n;
  cin >> n;
  string s;
  cin >> s;
  int a[n];
  memset(a, -1, sizeof(a));
  for (i = 0, k = n; s[i] != 0;) {
    for (; s[i] != '<' && s[i] != 0; i++)
      ;
    for (j = i; s[j] == '<' && s[j] != 0; j++)
      ;
    for (l = j - 1; l >= i; l--, k--) a[l + 1] = k;
    i = j;
  }
  a[0] = k--;
  for (i = 0; i < n; i++)
    if (a[i] == -1) a[i] = k--;
  for (i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
  memset(a, -1, sizeof(a));
  for (i = 0, k = 0; s[i] != 0;) {
    for (; s[i] != 0 && s[i] != '>'; i++)
      ;
    for (l = k, j = i; s[j] == '>' && s[j] != 0; j++, k++)
      ;
    for (l = k; i < j; i++, l--) a[i + 1] = l;
  }
  a[0] = ++k;
  for (i = 0, k++; i < n; i++)
    if (a[i] == -1) a[i] = k++;
  for (i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
