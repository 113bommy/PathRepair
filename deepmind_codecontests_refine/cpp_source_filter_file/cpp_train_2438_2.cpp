#include <bits/stdc++.h>
using namespace std;
bool B[101][101];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int b;
      cin >> b;
      B[i][b] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    int test = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      test = 0;
      for (int k = 1; k <= 100; k++)
        if (!B[i][k] && B[j][k]) test = 1;
      if (!test) break;
    }
    if (test)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
