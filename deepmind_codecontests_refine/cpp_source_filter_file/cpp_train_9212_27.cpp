#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 1e5 + 1;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
int a[3][2];
void check() {
  int k = 0;
  int t = 0;
  set<int> s;
  for (int i = 0; i < 3; i++) {
    k += a[i][0];
    s.insert(a[i][1]);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = i + 1; j < 3; j++) {
      t = a[i][1] + a[j][1];
      if (a[i][0] == a[j][0] && t == a[3 - i - j][1] &&
          a[i][0] + a[3 - i - j][0] == t) {
        cout << t << endl;
        for (int h = 0; h < a[i][0]; h++) {
          for (int f = 0; f < t; f++) {
            if (f < a[i][0])
              cout << char(i + 'A');
            else
              cout << char(j + 'A');
          }
          cout << endl;
        }
        for (int h = a[i][0]; h < t; h++) {
          for (int f = 0; f < t; f++) cout << char(3 - i - j + 'A');
          cout << endl;
        }
        exit(0);
      }
    }
  }
  if (s.size() == 1 && (*s.begin()) == k) {
    cout << k << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < a[i][0]; j++) {
        for (int h = 0; h < k; h++) cout << char(i + 'A');
        cout << endl;
      }
    }
    exit(0);
  }
}
int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) cin >> a[i][j];
  for (int i = 0; i < 2; i++) {
    if (i == 1) swap(a[0][0], a[0][1]);
    for (int j = 0; j < 2; j++) {
      if (j == 1) swap(a[1][0], a[1][1]);
      for (int h = 0; h < 2; h++) {
        if (h == 1) swap(a[2][0], a[2][1]);
        check();
        if (j == 1) swap(a[2][0], a[2][1]);
      }
      if (j == 1) swap(a[1][0], a[1][1]);
    }
  }
  cout << -1;
}
