#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int s[n];
  int f[10] = {0};
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int tmp;
  for (int j = 0; j < m; j++) {
    cin >> tmp;
    f[tmp] = 1;
  }
  int emp = 1;
  for (int i = 0; i < n - 1; i++) {
    if (f[s[i]] == 1) {
      emp = 0;
      cout << s[i] << " ";
    }
  }
  if (emp == 1) cout << "\n";
}
