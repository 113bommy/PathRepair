#include <bits/stdc++.h>
using namespace std;
int main() {
  bool P[1000000];
  memset(P, true, sizeof(P));
  int i, j, n, X, Root;
  for (i = 2; i * i < 1000001; i++) {
    if (P[i] == true) {
      for (j = i * i; j <= 1000000; j += i) P[j] = false;
    }
  }
  cin >> n;
  while (n--) {
    cin >> X;
    if (X == 1) {
      cout << "NO" << endl;
      continue;
    }
    Root = sqrt(X);
    if ((Root * Root) == X && P[Root] == true)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
