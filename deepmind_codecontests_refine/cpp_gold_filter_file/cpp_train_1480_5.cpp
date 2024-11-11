#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  if (abs(a + c - b - d) <= 1) {
    if (a <= b && c >= d) {
      puts("YES");
      if (a + c == b + d) {
        while (a && b) {
          cout << "0 1 ";
          --a;
          --b;
        }
        while (c && d) {
          cout << "2 3 ";
          --c;
          --d;
        }
        while (b && c) {
          cout << "2 1 ";
          --b;
          --c;
        }
      } else if (a + c > b + d) {
        while (a && b) {
          cout << "0 1 ";
          --a, --b;
        }
        while (c && d) {
          cout << "2 3 ";
          --c, --d;
        }
        while (b && c) {
          cout << "2 1 ";
          --b, --c;
        }
        cout << "2 ";
      } else {
        while (c && d) {
          cout << "3 2 ";
          --c, --d;
        }
        while (a && b) {
          cout << "1 0 ";
          --a, --b;
        }
        while (b && c) {
          cout << "1 2 ";
          --b, --c;
        }
        cout << "1 ";
      }
      cout << endl;
    } else if (a == b + 1 && c == d) {
      if (c) {
        puts("NO");
      } else {
        puts("YES");
        while (b) {
          cout << "0 1 ";
          --a, --b;
        }
        cout << "0 ";
        cout << endl;
      }
    } else if (d == c + 1 && a == b) {
      if (a) {
        puts("NO");
      } else {
        puts("YES");
        while (c) {
          cout << "3 2 ";
          --c, --d;
        }
        cout << "3 ";
        cout << endl;
      }
    } else
      puts("NO");
  } else
    puts("NO");
  return 0;
}
