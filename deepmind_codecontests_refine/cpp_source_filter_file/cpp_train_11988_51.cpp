#include <bits/stdc++.h>
using namespace std;
int a[11] = {2, 3, 4, 5, 12, 30, 35, 43, 46, 52, 64};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 11; i++) {
    if (a[i] == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
