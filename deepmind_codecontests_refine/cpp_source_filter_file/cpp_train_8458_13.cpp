#include <bits/stdc++.h>
using namespace std;
int main() {
  int turn, n, p;
  cin >> turn;
  for (int k = 0; k < turn; k++) {
    cin >> n;
    int a[50] = {0};
    for (int i = 0; i < n * 2; i++) {
      cin >> p;
      if (a[p] == 0) cout << p << " ";
      a[p] = 1;
    }
    cout << endl;
  }
  return 0;
}
