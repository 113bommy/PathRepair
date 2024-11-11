#include <bits/stdc++.h>
using namespace std;
int s[100010];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  int anw = 0;
  int p = 0;
  while ((k - p) * 2 > n && p < n) {
    p++;
    anw = max(s[n - p], anw);
  }
  int m = n - p;
  for (int i = 0; i * 2 < m; i++) {
    anw = max(anw, s[i] + s[m - i - 1]);
  }
  cout << anw << endl;
}
