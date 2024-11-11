#include <bits/stdc++.h>
using namespace std;
int n;
int a[100], maxs = 0;
string s;
int main() {
  cin >> s;
  int n = s.length();
  if (n == 1) {
    if (s[0] == '7' || s[0] == '3') {
      cout << "Yes";
      return 0;
    } else {
      cout << "No";
      return 0;
    }
  }
  if (s.length() % 2 != 0) {
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] == '4' && s[n - i - 1] != '6') {
        cout << "No";
        return 0;
      }
      if (s[i] == '6' && s[n - i - 1] != '4') {
        cout << "No";
        return 0;
      }
      if (s[i] == '5' && s[n - i - 1] != '9') {
        cout << "No";
        return 0;
      }
      if (s[i] == '9' && s[n - i - 1] != '5') {
        cout << "No";
        return 0;
      }
      if (s[i] == '8' && s[n - i - 1] != '0') {
        cout << "No";
        return 0;
      }
      if (s[i] == '0' && s[n - i - 1] != '8') {
        cout << "No";
        return 0;
      }
      if (s[i] == '3' && s[n - i - 1] != '3') {
        cout << "No";
        return 0;
      }
      if (s[i] == '7' && s[n - i - 1] != '7') {
        cout << "No";
        return 0;
      }
      if (s[i] == '1' || s[i] == '2' || s[n - i - 1] == '1' ||
          s[n - i - 1] == '2') {
        cout << "No";
        return 0;
      }
    }
    if (s[n / 2] != '1' && s[n / 2] != '2') {
      cout << "Yes";
    } else
      cout << "No";
  } else {
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == '4' && s[n - i - 1] != '6') {
        cout << "No";
        return 0;
      }
      if (s[i] == '6' && s[n - i - 1] != '4') {
        cout << "No";
        return 0;
      }
      if (s[i] == '5' && s[n - i - 1] != '9') {
        cout << "No";
        return 0;
      }
      if (s[i] == '9' && s[n - i - 1] != '5') {
        cout << "No";
        return 0;
      }
      if (s[i] == '8' && s[n - i - 1] != '0') {
        cout << "No";
        return 0;
      }
      if (s[i] == '0' && s[n - i - 1] != '8') {
        cout << "No";
        return 0;
      }
      if (s[i] == '3' && s[n - i - 1] != '3') {
        cout << "No";
        return 0;
      }
      if (s[i] == '7' && s[n - i - 1] != '7') {
        cout << "No";
        return 0;
      }
      if (s[i] == '1' || s[i] == '2' || s[n - i - 1] == '1' ||
          s[n - i - 1] == '2') {
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
  }
}
