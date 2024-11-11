#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << "a" << endl;
    cout << "c" << endl;
    cout << "c" << endl;
    cout << "a" << endl;
    return 0;
  }
  if (n == 2) {
    cout << "aa" << endl;
    cout << "cb" << endl;
    cout << "cb" << endl;
    cout << "aa" << endl;
    return 0;
  }
  if (n % 2) {
    for (int i = 0; i < (n - 1) / 2; ++i)
      if (i % 2)
        cout << "aa";
      else
        cout << "bb";
    cout << "c" << endl;
    for (int i = 0; i < (n - 1) / 2; ++i)
      if (i % 2 == 0)
        cout << "aa";
      else
        cout << "bb";
    cout << "c" << endl;
    cout << "c";
    for (int i = 0; i < (n - 1) / 2; ++i)
      if (i % 2)
        cout << "dd";
      else
        cout << "ee";
    cout << endl;
    cout << "c";
    for (int i = 0; i < (n - 1) / 2; ++i)
      if (i % 2 == 0)
        cout << "dd";
      else
        cout << "ee";
    cout << endl;
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; ++i)
      if (i % 2)
        cout << "aa";
      else
        cout << "bb";
    cout << endl;
    for (int i = 0; i < n / 2; ++i)
      if (i % 2 == 0)
        cout << "aa";
      else
        cout << "bb";
    cout << endl;
    cout << "c";
    for (int i = 0; i < (n - 1) / 2; ++i)
      if (i % 2)
        cout << "dd";
      else
        cout << "ee";
    cout << "c" << endl;
    cout << "c";
    for (int i = 0; i < (n - 1) / 2; ++i)
      if (i % 2 == 0)
        cout << "dd";
      else
        cout << "ee";
    cout << "c" << endl;
  }
  return 0;
}
