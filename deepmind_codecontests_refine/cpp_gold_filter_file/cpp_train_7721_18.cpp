#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a[n];
  int b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int s[m];
  for (int i = 0; i < m; i++) s[i] = 1;
  int l;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      l = 1;
      for (int k = j + 1; k < n; k++) {
        if (a[j][i] == a[k][i]) l++;
      }
      if (l > s[i]) s[i] = l;
    }
  }
  int c = 0;
  for (int i = 0; i < m; i++) c += s[i] * b[i];
  cout << c;
}
