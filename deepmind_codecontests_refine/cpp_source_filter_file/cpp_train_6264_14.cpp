#include <bits/stdc++.h>
using namespace std;
int n, v[100010];
int main() {
  cin >> n;
  int bj = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    if (v[i] == n)
      bj = 1;
    else {
      if (!bj) {
        if (v[i] < v[i - 1]) {
          cout << "NO";
          return 0;
        }
      } else {
        if (v[i] > v[i - 1]) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
}
