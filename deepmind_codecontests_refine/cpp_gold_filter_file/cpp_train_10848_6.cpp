#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b + c + d <= 2) {
    if (a + b + c + d == 1) {
      if (a == 1) {
        cout << "YES"
             << "\n";
        cout << "0";
      }
      if (b == 1) {
        cout << "YES"
             << "\n";
        cout << "1";
      }
      if (c == 1) {
        cout << "YES"
             << "\n";
        cout << "2";
      }
      if (d == 1) {
        cout << "YES"
             << "\n";
        cout << "3";
      }
    } else {
      if (a == 1 && b == 1) {
        cout << "YES"
             << "\n";
        cout << "0 "
             << "1";
      } else if (b == 1 && c == 1) {
        cout << "YES"
             << "\n";
        cout << "1 "
             << "2";
      } else if (c == 1 && d == 1) {
        cout << "YES"
             << "\n";
        cout << "2 "
             << "3";
      } else
        cout << "NO";
    }
  } else if (b == 0) {
    if (a != 0)
      cout << "NO";
    else if (c == d) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < c; i++)
        cout << "2 "
             << "3 ";
    } else if (c == d + 1) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < d; i++)
        cout << "2 "
             << "3 ";
      cout << "2";
    } else if (d == c + 1) {
      cout << "YES"
           << "\n";
      cout << "3 ";
      for (long long int i = 0; i < c; i++)
        cout << "2 "
             << "3 ";
    } else {
      cout << "NO";
    }
  } else if (c == 0) {
    if (d != 0)
      cout << "NO";
    else if (a == b) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
    } else if (a == b + 1) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < b; i++)
        cout << "0 "
             << "1 ";
      cout << "0";
    } else if (b == a + 1) {
      cout << "YES"
           << "\n";
      cout << "1 ";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
    } else {
      cout << "NO";
    }
  } else if (a > b || d > c)
    cout << "NO";
  else if (a == b && c == d) {
    cout << "YES"
         << "\n";
    for (long long int i = 0; i < a; i++)
      cout << "0 "
           << "1 ";
    for (long long int i = 0; i < c; i++)
      cout << "2 "
           << "3 ";
  } else if (a == b) {
    if (c == d + 1) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
      for (long long int i = 0; i < d; i++)
        cout << "2 "
             << "3 ";
      cout << "2";
    } else {
      cout << "NO";
    }
  } else if (c == d) {
    if (b == a + 1) {
      cout << "YES"
           << "\n";
      cout << "1 ";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
      for (long long int i = 0; i < d; i++)
        cout << "2 "
             << "3 ";
    } else {
      cout << "NO";
    }
  } else {
    if (b - a == c - d) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
      for (long long int i = 0; i < b - a; i++)
        cout << "2 "
             << "1 ";
      for (long long int i = 0; i < d; i++)
        cout << "2 "
             << "3 ";
    } else if (b - a == c - d + 1) {
      cout << "YES"
           << "\n";
      cout << "1 ";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
      for (long long int i = 0; i < c - d; i++)
        cout << "2 "
             << "1 ";
      for (long long int i = 0; i < d; i++)
        cout << "2 "
             << "3 ";
    } else if (b - a + 1 == c - d) {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < a; i++)
        cout << "0 "
             << "1 ";
      for (long long int i = 0; i < b - a; i++)
        cout << "2 "
             << "1 ";
      for (long long int i = 0; i < d; i++)
        cout << "2 "
             << "3 ";
      cout << "2";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
