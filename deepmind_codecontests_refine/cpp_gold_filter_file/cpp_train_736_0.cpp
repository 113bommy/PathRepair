#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n - 1][2], b[n - 1][2];
  int inp;
  for (int i = 0; i < n - 1; i++) {
    cin >> inp;
    if (inp == 0) {
      a[i][0] = 0;
      a[i][1] = 0;
    }
    if (inp == 1) {
      a[i][0] = 0;
      a[i][1] = 1;
    }
    if (inp == 2) {
      a[i][0] = 1;
      a[i][1] = 0;
    }
    if (inp == 3) {
      a[i][0] = 1;
      a[i][1] = 1;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> inp;
    if (inp == 0) {
      b[i][0] = 0;
      b[i][1] = 0;
    }
    if (inp == 1) {
      b[i][0] = 0;
      b[i][1] = 1;
    }
    if (inp == 2) {
      b[i][0] = 1;
      b[i][1] = 0;
    }
    if (inp == 3) {
      b[i][0] = 1;
      b[i][1] = 1;
    }
  }
  int ans[n][2];
  for (int i = 0; i < n; i++) {
    ans[i][0] = 2;
    ans[i][1] = 2;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i][0] == 0) {
      if (ans[i][0] != 1 && ans[i + 1][0] != 1) {
        ans[i][0] = 0;
        ans[i + 1][0] = 0;
      } else {
        cout << "NO";
        return 0;
      }
    }
    if (a[i][1] == 0) {
      if (ans[i][1] != 1 && ans[i + 1][1] != 1) {
        ans[i][1] = 0;
        ans[i + 1][1] = 0;
      } else {
        cout << "NO";
        return 0;
      }
    }
    if (b[i][0] == 1) {
      if (ans[i][0] != 0 && ans[i + 1][0] != 0) {
        ans[i][0] = 1;
        ans[i + 1][0] = 1;
      } else {
        cout << "NO";
        return 0;
      }
    }
    if (b[i][1] == 1) {
      if (ans[i][1] != 0 && ans[i + 1][1] != 0) {
        ans[i][1] = 1;
        ans[i + 1][1] = 1;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
  for (int j = 0; j < 5; j++) {
    for (int i = n - 2; i >= 0; i--) {
      if (a[i][0] == 1 && ans[i + 1][0] == 0) {
        if (ans[i][0] != 0) {
          ans[i][0] = 1;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (a[i][1] == 1 && ans[i + 1][1] == 0) {
        if (ans[i][1] != 0) {
          ans[i][1] = 1;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (a[i][0] == 1 && ans[i][0] == 0) {
        if (ans[i + 1][0] != 0) {
          ans[i + 1][0] = 1;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (a[i][1] == 1 && ans[i][1] == 0) {
        if (ans[i + 1][1] != 0) {
          ans[i + 1][1] = 1;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (b[i][0] == 0 && ans[i + 1][0] == 1) {
        if (ans[i][0] != 1) {
          ans[i][0] = 0;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (b[i][1] == 0 && ans[i + 1][1] == 1) {
        if (ans[i][1] != 1) {
          ans[i][1] = 0;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (b[i][0] == 0 && ans[i][0] == 1) {
        if (ans[i + 1][0] != 1) {
          ans[i + 1][0] = 0;
        } else {
          cout << "NO";
          return 0;
        }
      }
      if (b[i][1] == 0 && ans[i][1] == 1) {
        if (ans[i + 1][1] != 1) {
          ans[i + 1][1] = 0;
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i][0] == 2) {
      ans[i][0] = (i % 2) % 2;
    }
    if (ans[i][1] == 2) {
      ans[i][1] = (i % 2 + 1) % 2;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << 2 * ans[i][0] + ans[i][1] << ' ';
  }
  return 0;
}
