#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long i;
  if (n != 1) {
    bool flag = false;
    int firstno, a;
    cin >> firstno;
    if (firstno) {
      flag = true;
    }
    for (i = 1; i < n; ++i) {
      cin >> a;
      if (a != firstno) {
        break;
      }
    }
    if (n % i) {
      cout << "NO";
    } else {
      if (i == 1) {
        flag = !flag;
      }
      long m = i;
      ++i;
      ++i;
      for (; i < n; ++i) {
        cin >> a;
        if (a) {
          if (flag) {
            cout << "NO";
            exit(0);
          }
        } else {
          if (!flag) {
            cout << "NO";
            exit(0);
          }
        }
        if (i % m == 0) {
          flag = (!flag);
        }
      }
      cout << "YES";
    }
  } else {
    cout << "YES";
  }
}
