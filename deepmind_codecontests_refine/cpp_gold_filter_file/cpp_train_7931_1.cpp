#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    int a[100] = {0};
    bool isTwo = false;
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      a[temp - 1] = 1;
    }
    for (int j = 0; j < 99; j++) {
      if (a[j] == 1 && a[j + 1] == 1) isTwo = true;
    }
    if (isTwo)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
}
