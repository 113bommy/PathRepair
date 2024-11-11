#include <bits/stdc++.h>
using namespace std;
int b[105];
int main() {
  int n, m, a;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a;
    for (int j = a; j <= n; j++) {
      if (!b[j]) b[j] = a;
    }
  }
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
}
