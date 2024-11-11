#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, f, k;
  cin >> a >> b >> f >> k;
  if (k == 1) {
    if (b < f || b < (a - f)) {
      cout << -1;
      return 0;
    }
    if (a > b)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (k == 1) {
    if (b < f || b < 2 * (a - f)) {
      cout << -1;
      return 0;
    }
    int s = 1;
    long long cnt = 0;
    long long avl = b - f;
    long long dmd1 = 2 * (a - f);
    long long dmd0 = 2 * f;
    while (1) {
      if (k == 1) break;
      k--;
      if (s == 1) {
        if (avl >= dmd1)
          avl = avl - dmd1;
        else {
          cnt++;
          avl = b - dmd1;
        }
      } else {
        if (avl >= dmd0)
          avl = avl - dmd0;
        else {
          cnt++;
          avl = b - dmd0;
        }
      }
      s = s ^ 1;
    }
    if (s == 1) {
      if (avl < (a - f)) cnt++;
    }
    if (s == 0) {
      if (avl < f) cnt++;
    }
    cout << cnt;
    return 0;
  }
  if (f > b || (a - f) > b || 2 * f > b || 2 * (a - f) > b) {
    cout << -1;
    return 0;
  }
  int s = 1;
  long long cnt = 0;
  long long avl = b - f;
  long long dmd1 = 2 * (a - f);
  long long dmd0 = 2 * f;
  while (1) {
    if (k == 1) break;
    k--;
    if (s == 1) {
      if (avl >= dmd1)
        avl = avl - dmd1;
      else {
        cnt++;
        avl = b - dmd1;
      }
    } else {
      if (avl >= dmd0)
        avl = avl - dmd0;
      else {
        cnt++;
        avl = b - dmd0;
      }
    }
    s = s ^ 1;
  }
  if (s == 1) {
    if (avl < (a - f)) cnt++;
  }
  if (s == 0) {
    if (avl < f) cnt++;
  }
  cout << cnt;
}
