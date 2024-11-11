#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  int n1, n0, t, n;
  if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 0) {
    cout << "0";
    return 0;
  }
  if (a00 == 0) {
    if ((a01 == 0) && (a10 == 0))
      n0 = 0;
    else
      n0 = 1;
  } else {
    unsigned long long int temp = 1 + 8 * a00;
    unsigned long long int ta = sqrt(temp);
    if (ta * ta == temp) {
      if ((1 + ta) % 2 == 0) {
        n0 = (1 + ta) / 2;
      } else {
        cout << "Impossible \n";
        return 0;
      }
    } else {
      cout << "Impossible ";
      return 0;
    }
  }
  if (a11 == 0) {
    if ((a01 == 0) && (a10 == 0))
      n1 = 0;
    else
      n1 = 1;
  } else {
    unsigned long long int temp = 1 + 8 * a11;
    unsigned long long int ta = sqrt(temp);
    if ((ta * ta) == temp) {
      if ((1 + ta) % 2 == 0) {
        n1 = (1 + ta) / 2;
      } else {
        cout << "Impossible \n";
        return 0;
      }
    } else {
      cout << "Impossible ";
      return 0;
    }
  }
  if ((n0 == 0) && (n1 == 0)) {
    cout << "Impossible ";
    return 0;
  }
  if (n1 == 0) {
    string ans;
    while (n0) {
      cout << '0';
      n0--;
    }
    cout << "\n";
    return 0;
  }
  if (n0 == 0) {
    string ans;
    while (n1) {
      cout << '1';
      n1--;
    }
    cout << "\n";
    return 0;
  }
  if (a01 >= n1) {
    int z = (a01 / n1);
    if (n0 < z) {
      cout << "Impossible ";
      return 0;
    } else {
      int left0 = n0 - z;
      if (a01 % n1 == 0) {
        if (a10 != left0 * n1) {
          cout << "Impossible";
          return 0;
        } else {
          string ans = "";
          while (z) {
            cout << '0';
            z--;
          }
          while (n1) {
            cout << '1';
            n1--;
          }
          while (left0) {
            cout << '0';
            left0--;
          }
          cout << "\n";
          return 0;
        }
      } else {
        int l = a01 % n1;
        int aage = n1 - l;
        left0--;
        if (a10 != ((left0 * n1) + (aage))) {
          cout << "Impossible";
          return 0;
        } else {
          string ans = "";
          while (z) {
            cout << '0';
            z--;
          }
          while (aage) {
            cout << '1';
            aage--;
          }
          cout << '0';
          while (l) {
            cout << '1';
            l--;
          }
          while (left0) {
            cout << '0';
            left0--;
          }
          cout << "\n";
          return 0;
        }
      }
    }
  } else {
    int l = a01 % n1;
    int aage = n1 - l;
    int left0 = n0 - 1;
    if (a10 != ((left0 * n1) + (aage))) {
      cout << "Impossible";
      return 0;
    } else {
      string ans = "";
      while (aage) {
        cout << '1';
        aage--;
      }
      cout << '0';
      while (l) {
        cout << '1';
        l--;
      }
      while (left0) {
        cout << '0';
        left0--;
      }
      cout << "\n";
      return 0;
    }
  }
  return 0;
}
