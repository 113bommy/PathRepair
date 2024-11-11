#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[5];
int main() {
  int mx = -1;
  int mi = 1000000007;
  int pos;
  for (int i = 0; i < 3; i++) {
    cin >> a[i].x >> a[i].y;
    if (a[i].x < a[i].y) swap(a[i].x, a[i].y);
    if (a[i].x > mx) {
      pos = i;
      mx = a[i].x;
    }
  }
  if (pos == 0) {
    int tmp = a[1].y + a[2].y + a[pos].y;
    if (tmp == a[pos].x) {
      if (a[1].x == mx && a[2].x == mx) {
        cout << mx << endl;
        for (int j = 0; j < a[pos].y; j++) {
          for (int i = 0; i < mx; i++) cout << "A";
          cout << endl;
        }
        for (int i = 0; i < a[1].y; i++) {
          for (int j = 0; j < mx; j++) {
            cout << "B";
          }
          cout << endl;
        }
        for (int i = 0; i < a[2].y; i++) {
          for (int j = 0; j < mx; j++) cout << "C";
          cout << endl;
        }
        return 0;
      }
    }
    tmp = a[1].y + a[pos].y;
    if (tmp == mx) {
      int tmp2 = a[2].y + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].x + a[2].x == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "A";
            cout << endl;
          }
          for (int i = 0; i < a[1].y; i++) {
            for (int j = 0; j < a[1].x; j++) cout << "B";
            for (int j = 0; j < a[2].x; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
      tmp2 = a[2].x + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].x + a[2].y == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "A";
            cout << endl;
          }
          for (int i = 0; i < a[1].y; i++) {
            for (int j = 0; j < a[1].x; j++) cout << "B";
            for (int j = 0; j < a[2].y; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
    }
    tmp = a[1].x + a[pos].y;
    if (tmp == mx) {
      int tmp2 = a[2].y + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].y + a[2].x == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "A";
            cout << endl;
          }
          for (int i = 0; i < a[1].x; i++) {
            for (int j = 0; j < a[1].y; j++) cout << "B";
            for (int j = 0; j < a[2].x; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
      tmp2 = a[2].x + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].y + a[2].y == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "A";
            cout << endl;
          }
          for (int i = 0; i < a[1].x; i++) {
            for (int j = 0; j < a[1].y; j++) cout << "B";
            for (int j = 0; j < a[2].y; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
    }
  } else if (pos == 1) {
    int tmp = a[0].y + a[2].y + a[pos].y;
    if (tmp == a[pos].x) {
      if (a[0].x == mx && a[2].x == mx) {
        cout << mx << endl;
        for (int j = 0; j < a[pos].y; j++) {
          for (int i = 0; i < mx; i++) cout << "B";
          cout << endl;
        }
        for (int i = 0; i < a[0].y; i++) {
          for (int j = 0; j < mx; j++) {
            cout << "A";
          }
          cout << endl;
        }
        for (int i = 0; i < a[2].y; i++) {
          for (int j = 0; j < mx; j++) cout << "C";
          cout << endl;
        }
        return 0;
      }
    }
    tmp = a[0].y + a[pos].y;
    if (tmp == mx) {
      int tmp2 = a[2].y + a[pos].y;
      if (tmp2 == mx) {
        if (a[0].x + a[2].x == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "B";
            cout << endl;
          }
          for (int i = 0; i < a[0].y; i++) {
            for (int j = 0; j < a[0].x; j++) cout << "A";
            for (int j = 0; j < a[2].x; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
      tmp2 = a[2].x + a[pos].y;
      if (tmp2 == mx) {
        if (a[0].x + a[2].y == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "B";
            cout << endl;
          }
          for (int i = 0; i < a[0].y; i++) {
            for (int j = 0; j < a[0].x; j++) cout << "A";
            for (int j = 0; j < a[2].y; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
    }
    tmp = a[0].x + a[pos].y;
    if (tmp == mx) {
      int tmp2 = a[2].y + a[pos].y;
      if (tmp2 == mx) {
        if (a[0].y + a[2].x == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "B";
            cout << endl;
          }
          for (int i = 0; i < a[0].x; i++) {
            for (int j = 0; j < a[0].y; j++) cout << "A";
            for (int j = 0; j < a[2].x; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
      tmp2 = a[2].x + a[pos].y;
      if (tmp2 == mx) {
        if (a[0].y + a[2].y == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "B";
            cout << endl;
          }
          for (int i = 0; i < a[0].x; i++) {
            for (int j = 0; j < a[0].y; j++) cout << "A";
            for (int j = 0; j < a[2].y; j++) cout << "C";
            cout << endl;
          }
          return 0;
        }
      }
    }
  } else {
    int tmp = a[1].y + a[0].y + a[pos].y;
    if (tmp == a[pos].x) {
      if (a[1].x == mx && a[0].x == mx) {
        cout << mx << endl;
        for (int j = 0; j < a[pos].y; j++) {
          for (int i = 0; i < mx; i++) cout << "C";
          cout << endl;
        }
        for (int i = 0; i < a[1].y; i++) {
          for (int j = 0; j < mx; j++) {
            cout << "B";
          }
          cout << endl;
        }
        for (int i = 0; i < a[0].y; i++) {
          for (int j = 0; j < mx; j++) cout << "A";
          cout << endl;
        }
        return 0;
      }
    }
    tmp = a[1].y + a[pos].y;
    if (tmp == mx) {
      int tmp2 = a[0].y + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].x + a[0].x == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "C";
            cout << endl;
          }
          for (int i = 0; i < a[1].y; i++) {
            for (int j = 0; j < a[1].x; j++) cout << "B";
            for (int j = 0; j < a[0].x; j++) cout << "A";
            cout << endl;
          }
          return 0;
        }
      }
      tmp2 = a[0].x + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].x + a[0].y == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "C";
            cout << endl;
          }
          for (int i = 0; i < a[1].y; i++) {
            for (int j = 0; j < a[1].x; j++) cout << "B";
            for (int j = 0; j < a[0].y; j++) cout << "A";
            cout << endl;
          }
          return 0;
        }
      }
    }
    tmp = a[1].x + a[pos].y;
    if (tmp == mx) {
      int tmp2 = a[0].y + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].y + a[0].x == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "C";
            cout << endl;
          }
          for (int i = 0; i < a[1].x; i++) {
            for (int j = 0; j < a[1].y; j++) cout << "B";
            for (int j = 0; j < a[0].x; j++) cout << "A";
            cout << endl;
          }
          return 0;
        }
      }
      tmp2 = a[0].x + a[pos].y;
      if (tmp2 == mx) {
        if (a[1].y + a[0].y == mx) {
          cout << mx << endl;
          for (int i = 0; i < a[pos].y; i++) {
            for (int j = 0; j < mx; j++) cout << "C";
            cout << endl;
          }
          for (int i = 0; i < a[1].x; i++) {
            for (int j = 0; j < a[1].y; j++) cout << "B";
            for (int j = 0; j < a[0].y; j++) cout << "A";
            cout << endl;
          }
          return 0;
        }
      }
    }
  }
  cout << "-1" << endl;
}
