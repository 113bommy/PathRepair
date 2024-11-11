#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int a[10005];
int main() {
  int n;
  while (cin >> n) {
    int t, num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> t;
      if (t == 2)
        num1++;
      else
        num2++;
    }
    if (num1 >= 1 && num2 >= 1) cout << 2 << " " << 1 << " ", num1--, num2--;
    for (int i = num1; i > 0; num1--, i--) cout << 2 << " ";
    for (int i = num2; i > 0; num2--, i--) cout << 1 << " ";
  }
  return 0;
}
