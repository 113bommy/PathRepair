#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string F;
  char f[3];
  cin >> n >> m;
  cin.ignore();
  if (n % 3 != 0 && m % 3 != 0)
    cout << "NO" << endl;
  else if (n % 3 != 0 && m % 3 == 0) {
    cin >> F;
    f[0] = F[0];
    f[1] = F[m / 3];
    f[2] = F[2 * m / 3];
    if (f[1] == f[0] || f[2] == f[0] || f[1] == f[2]) {
      cout << "NO" << endl;
      return 0;
    }
    for (int i = 0; i < m; i++) {
      if (i < m / 3) {
        if (F[i] != f[0]) {
          cout << "NO" << endl;
          return 0;
        }
      } else if (i < 2 * m / 3) {
        if (F[i] != f[1]) {
          cout << "NO" << endl;
          return 0;
        }
      } else {
        if (F[i] != f[2]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    for (int j = 1; j < n; j++) {
      cin >> F;
      for (int i = 0; i < m; i++) {
        if (i < m / 3) {
          if (F[i] != f[0]) {
            cout << "NO" << endl;
            return 0;
          }
        } else if (i < 2 * m / 3) {
          if (F[i] != f[1]) {
            cout << "NO" << endl;
            return 0;
          }
        } else {
          if (F[i] != f[2]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
    }
    cout << "YES" << endl;
    return 0;
  } else if (n % 3 == 0 && m % 3 != 0) {
    cin >> F;
    f[0] = F[0];
    for (int i = 1; i < m; i++) {
      if (F[i] != f[0]) {
        cout << "NO" << endl;
        return 0;
      }
    }
    for (int j = 1; j < n / 3; j++) {
      cin >> F;
      for (int i = 0; i < m; i++) {
        if (F[i] != f[0]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    cin >> F;
    f[1] = F[0];
    for (int i = 1; i < m; i++) {
      if (F[i] != f[1]) {
        cout << "NO" << endl;
        return 0;
      }
    }
    for (int j = 1; j < n / 3; j++) {
      cin >> F;
      for (int i = 0; i < m; i++) {
        if (F[i] != f[1]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    cin >> F;
    f[2] = F[0];
    if (f[1] == f[0] || f[2] == f[0] || f[1] == f[2]) {
      cout << "NO" << endl;
      return 0;
    }
    for (int i = 1; i < m; i++) {
      if (F[i] != f[2]) {
        cout << "NO" << endl;
        return 0;
      }
    }
    for (int j = 1; j < n / 3; j++) {
      cin >> F;
      for (int i = 0; i < m; i++) {
        if (F[i] != f[2]) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    cout << "YES" << endl;
  } else {
    cin >> F;
    f[0] = F[0];
    string F1 = F;
    for (int i = 0; i < m; i++) {
      F1[i] = F[0];
    }
    if (F == F1) {
      for (int i = 1; i < m; i++) {
        if (F[i] != f[0]) {
          cout << "NO" << endl;
          return 0;
        }
      }
      for (int j = 1; j < n / 3; j++) {
        cin >> F;
        for (int i = 0; i < m; i++) {
          if (F[i] != f[0]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
      cin >> F;
      f[1] = F[0];
      for (int i = 1; i < m; i++) {
        if (F[i] != f[1]) {
          cout << "NO" << endl;
          return 0;
        }
      }
      for (int j = 1; j < n / 3; j++) {
        cin >> F;
        for (int i = 0; i < m; i++) {
          if (F[i] != f[1]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
      cin >> F;
      f[2] = F[0];
      if (f[1] == f[0] || f[2] == f[0] || f[1] == f[2]) {
        cout << "NO" << endl;
        return 0;
      }
      for (int i = 1; i < m; i++) {
        if (F[i] != f[2]) {
          cout << "NO" << endl;
          return 0;
        }
      }
      for (int j = 1; j < n / 3; j++) {
        cin >> F;
        for (int i = 1; i < m; i++) {
          if (F[i] != f[2]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
      cout << "YES" << endl;
    } else {
      f[1] = F[m / 3];
      f[2] = F[2 * m / 3];
      if (f[1] == f[0] || f[2] == f[0] || f[1] == f[2]) {
        cout << "NO" << endl;
        return 0;
      }
      for (int i = 0; i < m; i++) {
        if (i < m / 3) {
          if (F[i] != f[0]) {
            cout << "NO" << endl;
            return 0;
          }
        } else if (i < 2 * m / 3) {
          if (F[i] != f[1]) {
            cout << "NO" << endl;
            return 0;
          }
        } else {
          if (F[i] != f[2]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
      for (int j = 1; j < n; j++) {
        cin >> F;
        for (int i = 0; i < m; i++) {
          if (i < m / 3) {
            if (F[i] != f[0]) {
              cout << "NO" << endl;
              return 0;
            }
          } else if (i < 2 * m / 3) {
            if (F[i] != f[1]) {
              cout << "NO" << endl;
              return 0;
            }
          } else {
            if (F[i] != f[2]) {
              cout << "NO" << endl;
              return 0;
            }
          }
        }
      }
      cout << "YES" << endl;
      return 0;
    }
  }
  return 0;
}
