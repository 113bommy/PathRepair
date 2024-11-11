#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[11];
  for (int i = 0; i < 11; ++i) a[i] = 2;
  for (int i = 0; i < n; ++i) {
    char o;
    int x;
    cin >> o >> x;
    if (o == '|') {
      for (int i = 0; i < 11; ++i) {
        if (x % 2 == 1) a[i] = 1;
        x /= 2;
      }
    } else if (o == '^') {
      for (int i = 0; i < 11; ++i) {
        if (x % 2 == 1) {
          if (a[i] == -1)
            a[i] = 2;
          else if (a[i] == 2)
            a[i] = -1;
          else if (a[i] == 0)
            a[i] = 1;
          else
            a[i] = 0;
        }
        x /= 2;
      }
    } else {
      for (int i = 0; i < 11; ++i) {
        if (x % 2 == 0) a[i] = 0;
        x /= 2;
      }
    }
  }
  long long int a1 = 0, a2 = 0, a3 = 0;
  long long int y = 1;
  for (int i = 0; i < 11; ++i) {
    if (a[i] == -1) {
      a2 += y;
      a3 += y;
    } else if (a[i] == 1) {
      a1 += y;
      a3 += y;
    } else if (a[i] == 2)
      a3 += y;
    y *= 2;
  }
  cout << 3 << endl;
  cout << "| " << a1 << endl;
  cout << "^ " << a2 << endl;
  cout << "& " << a3 << endl;
}
