#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, arr[101];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a;
    for (int j = 0; j < a; j++) {
      cin >> b;
      arr[b]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (arr[i] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
