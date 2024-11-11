#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct node {
  int x;
};
bool cmp(node a, node b) { return a.x < b.x; }
long long int poww(long long int a, long long int b) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > 1000000007) x %= 1000000007;
    }
    y = (y * y);
    if (y > 1000000007) y %= 1000000007;
    b /= 2;
  }
  return x;
}
int main() {
  int n, t, i, j, k, diff, x;
  scanf("%d", &n);
  scanf("%d", &t);
  char a[n + 2], b[n + 2], c[n + 2];
  scanf("%s", a);
  scanf("%s", b);
  diff = 0;
  for (i = 0; i < n; i++) {
    if (a[i] != b[i]) diff++;
  }
  for (i = 0; i < n; i++) c[i] = a[i];
  if (diff < t) {
    for (i = 0; i < n; i++) {
      if (a[i] != b[i] && t) {
        for (j = 97; j < 123; j++) {
          char x = j;
          if (a[i] != x && b[i] != x) {
            c[i] = x;
            break;
          }
        }
        t--;
      }
    }
    for (i = 0; i < n; i++) {
      if (a[i] == b[i] && t) {
        for (j = 97; j < 123; j++) {
          char x = j;
          if (a[i] != x) {
            c[i] = x;
            break;
          }
        }
        t--;
      }
    }
    c[n] = '\0';
    cout << c;
  } else if (diff == t) {
    for (i = 0; i < n; i++) {
      if (a[i] != b[i] && t) {
        for (j = 97; j < 123; j++) {
          char x = j;
          if (a[i] != x && b[i] != x) {
            c[i] = x;
            break;
          }
        }
        t--;
      }
    }
    c[n] = '\0';
    cout << c;
  } else {
    if ((diff - t) < t) {
      x = 2 * t - diff;
      for (i = 0; i < n; i++) {
        if (x == 0) break;
        if (a[i] != b[i]) {
          for (j = 97; j < 123; j++) {
            char x = j;
            if (a[i] != x && b[i] != x) {
              c[i] = x;
              break;
            }
          }
          x--;
        }
      }
      x = diff - t;
      for (j = i; j < n; j++) {
        if (x == 0) break;
        if (a[i] != b[i]) {
          c[i] = b[i];
          x--;
        }
      }
      c[n] = '\0';
      cout << c;
    } else
      cout << "-1";
  }
  return 0;
}
