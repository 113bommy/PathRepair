#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int hr, min;
  hr = (s[0] - '0') * 10 + (s[1] - '0');
  min = (s[3] - '0') * 10 + (s[4] - '0');
  if (hr <= 23) {
    switch (hr) {
      case 0: {
        if (min > 0)
          cout << 60 - min + 10 << endl;
        else
          cout << "0" << endl;
        break;
        return 0;
      }
      case 1: {
        if (min > 10)
          cout << 60 - min + 20 << endl;
        else
          cout << 10 - min << endl;
        break;
        return 0;
      }
      case 2: {
        if (min > 20)
          cout << 60 - min + 30 << endl;
        else
          cout << 20 - min << endl;
        break;
        return 0;
      }
      case 3: {
        if (min > 30)
          cout << 60 - min + 40 << endl;
        else
          cout << 30 - min << endl;
        break;
        return 0;
      }
      case 4: {
        if (min > 40)
          cout << 60 - min + 50 << endl;
        else
          cout << 40 - min << endl;
        break;
        return 0;
      }
      case 5: {
        if (min <= 50)
          cout << 50 - min << endl;
        else
          cout << 60 - min + 240 + 1 << endl;
        break;
        return 0;
      }
      case 6: {
        cout << (3 * 60) + 60 - min + 1 << endl;
        break;
        return 0;
      }
      case 7: {
        cout << (2 * 60) + 60 - min + 1 << endl;
        break;
        return 0;
      }
      case 8: {
        cout << (1 * 60) + 60 - min + 1 << endl;
        break;
        return 0;
      }
      case 9: {
        cout << 60 - min + 1 << endl;
        break;
        return 0;
      }
      case 10: {
        if (min <= 1)
          cout << 1 - min << endl;
        else
          cout << 60 - min + 11 << endl;
        break;
        return 0;
      }
      case 11: {
        if (min <= 11)
          cout << 11 - min << endl;
        else
          cout << 60 - min + 21 << endl;
        break;
        return 0;
      }
      case 12: {
        if (min <= 21)
          cout << 21 - min << endl;
        else
          cout << 60 - min + 31 << endl;
        break;
        return 0;
      }
      case 13: {
        if (min <= 31)
          cout << 31 - min << endl;
        else
          cout << 60 - min + 41 << endl;
        break;
        return 0;
      }
      case 14: {
        if (min <= 41)
          cout << 41 - min << endl;
        else
          cout << 60 - min + 51 << endl;
        break;
        return 0;
      }
      case 15: {
        if (min <= 51)
          cout << 51 - min << endl;
        else
          cout << 60 - min + (4 * 60) + 2 << endl;
        break;
        return 0;
      }
      case 16: {
        cout << 60 - min + (3 * 60) + 2 << endl;
        break;
        return 0;
      }
      case 17: {
        cout << 60 - min + (2 * 60) + 2 << endl;
        break;
        return 0;
      }
      case 18: {
        cout << 60 - min + (1 * 60) + 2 << endl;
        break;
        return 0;
      }
      case 19: {
        cout << 60 - min + 2 << endl;
        break;
        return 0;
      }
      case 20: {
        if (min <= 2)
          cout << 2 - min << endl;
        else
          cout << 60 - min + 12 << endl;
        break;
        return 0;
      }
      case 21: {
        if (min <= 12)
          cout << 12 - min << endl;
        else
          cout << 60 - min + 22 << endl;
        break;
        return 0;
      }
      case 22: {
        if (min <= 22)
          cout << 22 - min << endl;
        else
          cout << 60 - min + 32 << endl;
        break;
        return 0;
      }
      case 23: {
        if (min <= 32)
          cout << 32 - min << endl;
        else
          cout << 60 - min << endl;
        break;
        return 0;
      }
    }
  }
  return 0;
}
