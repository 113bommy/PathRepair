#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    int a[6];
    for (int i = 0; i < 6; i++) {
      cin >> a[i];
    }
    for (int i = 1;; i++) {
      for (int j = 0; j < 6; j++) {
        if (i == a[j]) {
          break;
        } else if (j == 5) {
          cout << i - 1 << endl;
          return 0;
        }
      }
    }
  } else if (n == 2) {
    int a[6], a1[6];
    set<int> x, x1;
    for (int i = 0; i < 6; i++) {
      cin >> a[i];
      x.insert(a[i]);
    }
    for (int i = 0; i < 6; i++) {
      cin >> a1[i];
      x1.insert(a1[i]);
    }
    for (int i = 1;; i++) {
      if (i < 10) {
        set<int>::iterator b, b1;
        b = x.find(i);
        b1 = x1.find(i);
        if (b != x.end() || b1 != x1.end()) {
        } else {
          cout << i - 1 << endl;
          return 0;
        }
      } else if (i < 100) {
        set<int>::iterator b, b1;
        set<int>::iterator c, c1;
        b = x.find(i % 10);
        b1 = x.find(i / 10);
        c = x1.find(i % 10);
        c1 = x1.find(i / 10);
        if (c != x1.end() && b1 != x.end() || c1 != x1.end() && b != x.end()) {
        } else {
          cout << i - 1 << endl;
          return 0;
        }
      } else {
        cout << i - 1 << endl;
        return 0;
      }
    }
  } else if (n == 3) {
    int a[6], a1[6], a2[6];
    set<int> x, x1, x2;
    for (int i = 1; i < 6; i++) {
      cin >> a[i];
      x.insert(a[i]);
    }
    for (int i = 0; i < 6; i++) {
      cin >> a1[i];
      x1.insert(a1[i]);
    }
    for (int i = 0; i < 6; i++) {
      cin >> a2[i];
      x2.insert(a2[i]);
    }
    for (int i = 1;; i++) {
      if (i < 10) {
        set<int>::iterator b, b1, b2;
        b = x.find(i);
        b1 = x1.find(i);
        b2 = x2.find(i);
        if (b != x.end() || b1 != x1.end() || b2 != x2.end()) {
        } else {
          cout << i - 1 << endl;
          return 0;
        }
      } else if (i < 100) {
        set<int>::iterator b, b1;
        set<int>::iterator c, c1;
        set<int>::iterator d, d1;
        b = x.find(i % 10);
        b1 = x.find(i / 10);
        c = x1.find(i % 10);
        c1 = x1.find(i / 10);
        d = x2.find(i % 10);
        d1 = x2.find(i / 10);
        if (b != x.end() && c1 != x1.end() || b != x.end() && d1 != x2.end()) {
        } else if (c != x1.end() && b1 != x.end() ||
                   c != x1.end() && d1 != x2.end()) {
        } else if (d != x2.end() && c1 != x1.end() ||
                   d != x2.end() && b1 != x.end()) {
        } else {
          cout << i - 1 << endl;
          return 0;
        }
      } else {
        set<int>::iterator b, b1, b2;
        set<int>::iterator c, c1, c2;
        set<int>::iterator d, d1, d2;
        b = x.find(i % 10);
        b1 = x.find((i / 10) % 10);
        b2 = x.find(i / 100);
        c = x1.find(i % 10);
        c1 = x1.find((i / 10) % 10);
        c2 = x1.find(i / 100);
        d = x2.find(i % 10);
        d1 = x2.find((i / 10) % 10);
        d2 = x2.find(i / 1000);
        if (b != x.end() && c1 != x1.end() && d2 != x2.end() ||
            b != x.end() && d1 != x2.end() && c2 != x1.end()) {
        } else if (c != x1.end() && b1 != x.end() && d2 != x2.end() ||
                   c != x1.end() && d1 != x2.end() && b2 != x.end()) {
        } else if (d != x2.end() && c1 != x1.end() && b2 != x.end() ||
                   d != x2.end() && b1 != x.end() && c2 != x1.end()) {
        } else {
          cout << i - 1 << endl;
          return 0;
        }
      }
    }
  }
}
