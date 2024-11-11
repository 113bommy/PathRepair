#include <bits/stdc++.h>
using namespace std;
struct cosa {
  int words;
  int next[26];
};
struct cost {
  long long int a, b, c;
};
struct q {
  int a;
  string b;
};
int alfa, beta;
int act;
char buffer[10];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool operator<(const cost &a, const cost &b) {
  if (a.a == b.a) {
    if (a.b == b.b) {
      return a.c < b.c;
    }
    return a.b < b.b;
  }
  return a.a < b.a;
}
string k;
long long int troy[200100];
cost tray[200100];
int main() {
  char prof;
  ios_base::sync_with_stdio(0);
  long long int x = 0, y = 0, z, mal = 2000000000, s = 0, d = -2, a1 = 0, b1,
                c1, x1, y1, t, res = 0, e, f;
  long long int a, b, c;
  int fark = 0;
  cin >> a;
  for (int i = int(0); i < int(a); i++) {
    cin >> troy[i];
    troy[i]--;
    if (i != 0 && troy[i] == troy[i - 1]) {
      cout << "NO";
      return 0;
    }
    if (i != 0 && s == 0) {
      if (troy[i - 1] + 1 == troy[i] || troy[i] - 1 == troy[i + 1]) {
      } else {
        s = troy[i] - troy[i - 1];
      }
    }
  }
  if (s < 0) {
    s *= -1;
  }
  if (s == 0) {
    cout << "YES" << endl << "1000000000 1000000000";
    return 0;
  }
  for (int i = int(0); i < int(a); i++) {
    tray[i].a = troy[i] / s;
    tray[i].b = troy[i] % s;
    if (i != 0) {
      if (tray[i - 1].a == tray[i].a) {
        if (tray[i - 1].b + 1 == tray[i].b || tray[i - 1].b - 1 == tray[i].b) {
        } else {
          cout << "NO";
          return 0;
        }
      } else {
        if (tray[i - 1].b == tray[i].b) {
          if (tray[i - 1].a + 1 == tray[i].a ||
              tray[i - 1].a - 1 == tray[i].a) {
          } else {
            cout << "NO";
            return 0;
          }
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl << "1000000000 " << s;
}
