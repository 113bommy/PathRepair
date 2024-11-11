#include <bits/stdc++.h>
using namespace std;
int check[110];
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 0;
    return 0;
  } else {
    int a, b, c, i;
    for (i = 0; i < m; i++) {
      cin >> a >> b >> c;
      check[a] = check[a] - c;
      check[b] = check[b] + c;
    }
  }
  int result = 0;
  for (int i = 0; i < 110; i++) {
    if (check[i] > 0) result += check[i];
  }
  cout << result;
  return 0;
}
