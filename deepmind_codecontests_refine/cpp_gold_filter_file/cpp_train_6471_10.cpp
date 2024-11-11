#include <bits/stdc++.h>
using namespace std;
int baze(int n) {
  if (n == 0) return 0;
  int res = 1;
  for (int i = 1; i < n; i++) {
    res *= 10;
  }
  res *= 9;
  res *= n;
  return res;
}
int b(int n) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += (baze(i));
  }
  return res;
}
int checker(int n) {
  int i = 0;
  while (true) {
    if (b(i) < n and n <= b(i + 1)) {
      return i;
    }
    i++;
  }
}
int f(int k) {
  int h = k;
  h -= b(checker(k));
  int r = checker(k) + 1;
  for (int i = 0; i < r; i++) {
    if (h % r == i) {
      if (i == 0) i = r;
      return i;
    }
  }
}
int finder(int k, int r) {
  int h = k;
  while (h % r != 0) {
    h++;
  }
  int res = (h / r);
  for (int i = 1; i < r; i++) {
    res += (baze(i) / i);
  }
  return res;
}
int finisher(int a, int b) {
  int r = 0;
  int h = a;
  while (h > 0) {
    r++;
    h /= 10;
  }
  h = a;
  for (int i = 0; i < r - b; i++) {
    a /= 10;
  }
  return a % 10;
}
int main() {
  int k;
  cin >> k;
  cout << finisher(finder(k - b(checker(k)), checker(k) + 1), f(k));
}
