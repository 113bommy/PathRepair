#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
struct c {
  int n;
  int d = 1;
  int w;
};
int main() {
  int n, c1 = 0;
  cin >> n;
  char a[n];
  int c[n];
  for (int i = 0; i < n; i++) {
    c[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] == a[1]) {
    c1++;
    if (a[0] != 'R') {
      a[0] = 'R';
    } else if (a[0] != 'G') {
      a[0] = 'G';
    } else {
      a[0] = 'B';
    }
  }
  for (int i = 1; i < n - 2; i++) {
    if (a[i + 1] == a[i]) {
      c1++;
      if (a[i + 1] != 'R' && a[i + 2] != 'R') {
        a[i + 1] = 'R';
      } else if (a[i + 1] != 'G' && a[i + 2] != 'G') {
        a[i + 1] = 'G';
      } else if (a[i + 1] != 'B' && a[i + 2] != 'B') {
        a[i + 1] = 'B';
      }
    }
  }
  if (a[n - 1] == a[n - 2]) {
    c1++;
    if (a[n - 2] != 'R') {
      a[n - 1] = 'R';
    } else if (a[n - 2] != 'G') {
      a[n - 1] = 'G';
    } else {
      a[n - 1] = 'B';
    }
  }
  cout << c1 << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  return 0;
}
