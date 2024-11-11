#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
bool dio(int a, int b, int c, int& x0, int& y0, int& g) {
  int k = 0;
  while ((c - k * a) % b) {
    k++;
    if (k * a > c) return false;
  }
  x0 = k;
  y0 = (c - k * a) / b;
  return true;
}
bool check(vector<int>& d, int a, int b) {
  for (int i = 0; i < d.size(); i++) {
    int j = 1;
    int k = i;
    while (d[k] != i + 1) {
      k = d[k] - 1;
      j++;
    }
    if (j != a && j != b) return false;
  }
  return true;
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int x, y, g;
  if (!dio(a, b, n, x, y, g))
    cout << -1;
  else {
    int k = 1;
    while (x) {
      cout << k * a << ' ';
      for (int i = 1; i < a; i++) cout << i + (k - 1) * a << ' ';
      x--;
      k++;
    }
    int k1 = 1;
    k--;
    while (y) {
      cout << k1 * b + k * a << ' ';
      for (int i = 1; i < b; i++) cout << i + (k1 - 1) * b + k * a << ' ';
      y--;
      k1++;
    }
  }
}
