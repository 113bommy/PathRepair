#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (n % 2 == 1) {
    cout << n - 1 << " ";
    int i = 1;
    while (i <= n - 1) {
      cout << i << " ";
      i++;
    }
    cout << endl << 1 << " " << n << endl;
  } else {
    cout << n - 1 << " ";
    int i = 1;
    while (i <= n) {
      if (i != n / 2) cout << i << " ";
      i++;
    }
    cout << endl << 1 << " " << n / 2 << endl;
  }
  return 0;
}
