#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << "a\na\nb\nb\n";
  } else if (n == 2) {
    cout << "aa\n";
    cout << "bb\n";
    cout << "aa\n";
    cout << "bb\n";
  } else if (n == 3) {
    cout << "aab\n";
    cout << "ccb\n";
    cout << "baa\n";
    cout << "bcc\n";
  } else if (n % 2 == 0) {
    cout << "xx";
    for (int i = 0; i < (n - 4) / 2;) {
      cout << "oo";
      i++;
      if (i < (n - 4) / 2) cout << "ii";
      i++;
    }
    cout << "yy\n";
    cout << "z";
    for (int i = 0; i < (n - 2) / 2;) {
      cout << "aa";
      i++;
      if (i < (n - 2) / 2) cout << "bb";
      i++;
    }
    cout << "z\n";
    cout << "z";
    for (int i = 0; i < (n - 2) / 2;) {
      cout << "cc";
      i++;
      if (i < (n - 2) / 2) cout << "dd";
      i++;
    }
    cout << "z\n";
    cout << "yy";
    for (int i = 0; i < (n - 4) / 2;) {
      cout << "oo";
      i++;
      if (i < (n - 4) / 2) cout << "ii";
      i++;
    }
    cout << "xx\n";
  } else {
    for (int i = 0; i < n / 2;) {
      cout << "aa";
      i++;
      if (i < n / 2) cout << "bb";
      i++;
    }
    cout << "x\n";
    for (int i = 0; i < n / 2;) {
      cout << "cc";
      i++;
      if (i < n / 2) cout << "dd";
      i++;
    }
    cout << "x\n";
    cout << "x";
    for (int i = 0; i < n / 2;) {
      cout << "aa";
      i++;
      if (i < n / 2) cout << "bb";
      i++;
    }
    cout << "\n";
    cout << "x";
    for (int i = 0; i < n / 2; i) {
      cout << "cc";
      i++;
      if (i < n / 2) cout << "dd";
      i++;
    }
    cout << "\n";
  }
  return 0;
}
