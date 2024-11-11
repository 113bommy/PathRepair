#include <bits/stdc++.h>
using namespace std;
char s[100001];
int t[27];
int main() {
  int n, k, i, m;
  cin >> n >> k;
  cin.get();
  cin.get(s, 100001);
  m = 999999;
  for (i = 0; i < n; i++) t[s[i] - 'A' + 1]++;
  for (i = 1; i <= k; i++)
    if (t[i] < m) m = t[i];
  cout << m * k;
  return 0;
}
