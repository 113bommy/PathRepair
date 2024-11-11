#include <bits/stdc++.h>
using namespace std;
int n;
int k;
void f(int a) {
  int h = 0;
  if (a == 1) {
    while (h < k * k) {
      if (h != 0 && (h / k) % 2 != ((h - 1) / k) % 2) cout << '\n';
      if ((h / k) % 2 == 0)
        if ((h % k) % 4 == 0 || (h % k) % 4 == 1)
          cout << "b";
        else
          cout << "w";
      else if ((h % k) % 4 == 0 || (h % k) % 4 == 1)
        cout << "w";
      else
        cout << "b";
      h++;
    }
  }
  if (a == 2) {
    while (h < k * k) {
      if (h != 0 && (h / k) % 2 != ((h - 1) / k) % 2) cout << '\n';
      if ((h / k) % 2 == 0)
        if ((h % k) % 4 == 0 || (h % k) % 4 == 1)
          cout << "w";
        else
          cout << "b";
      else if ((h % k) % 4 == 0 || (h % k) % 4 == 1)
        cout << "b";
      else
        cout << "w";
      h++;
    }
  }
}
int main() {
  cin >> n;
  k = n;
  if (n % 2 == 1) {
    cout << -1 << '\n';
    return 0;
  }
  while (n >= 4) {
    f(1);
    cout << '\n';
    f(1);
    cout << '\n';
    f(2);
    cout << '\n';
    f(2);
    cout << '\n';
    n -= 4;
    cout << '\n';
  }
  if (n != 0) {
    f(1);
    cout << '\n';
    f(1);
    cout << '\n';
  }
  return 0;
}
