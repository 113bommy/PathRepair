#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[100009];
int main() {
  int a, mx = 0, sum = 0, x;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> x;
    sum += x;
    umax(mx, x);
  }
  umax(mx, (sum + a - 2) / (a - 1));
  cout << mx << endl;
  return 0;
}
