#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 != 0 && n < 101) {
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 1; j <= n; j++) {
        if (j < ((n / 2 + 1) - (i - 1)))
          cout << "*";
        else if (j > ((n / 2 + 1) + (i - 1)))
          cout << "*";
        else
          cout << "D";
      }
      cout << endl;
    }
    for (int j = 1; j <= n; j++) {
      cout << "D";
    }
    cout << endl;
    for (int i = n / 2 + 2; i <= n; i++) {
      int str = i - (n / 2 + 1), j;
      for (j = 1; j <= str; j++) cout << "*";
      for (j = str + 1; j <= n - str; j++) cout << "D";
      while (j <= n) {
        cout << "*";
        j++;
      }
      cout << endl;
    }
  }
}
