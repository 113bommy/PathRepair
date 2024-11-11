#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, countof0 = 0, countof1 = 0;
  cin >> n;
  char a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 'z') {
      countof0++;
    } else if (a[i] == 'n') {
      countof1++;
    }
  }
  for (i = 0; i < countof1; i++) {
    cout << "1";
  }
  while (countof0--) {
    cout << "0";
  }
  cout << endl;
}
