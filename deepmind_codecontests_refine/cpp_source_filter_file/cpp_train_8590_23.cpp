#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, d, h;
  cin >> n >> d >> h;
  if (d > 2 * h) {
    cout << -1 << endl;
    return 0;
  }
  if (h == 1 && d == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 1 << " " << 2 << endl;
    return 0;
  } else if (n == 3) {
    if (h == 1) {
      if (d == 2) {
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 3 << endl;
        return 0;
      } else {
        cout << -1 << endl;
        return 0;
      }
    } else if (h == 2) {
      if (d == 2) {
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 3 << endl;
        return 0;
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  long long int height = h, vertex = 1, temp = d - h;
  while (height--) {
    cout << vertex << " " << vertex + 1 << endl;
    vertex++;
  }
  if (temp == 0) {
    while (vertex < n) {
      cout << 2 << " " << vertex + 1 << endl;
      vertex++;
    }
    return 0;
  }
  while (vertex < n) {
    temp = d - h;
    vertex++;
    cout << 1 << " " << vertex << endl;
    temp--;
    while (temp-- && vertex < n) {
      cout << vertex << " " << vertex + 1 << endl;
      vertex++;
    }
  }
  return 0;
}
