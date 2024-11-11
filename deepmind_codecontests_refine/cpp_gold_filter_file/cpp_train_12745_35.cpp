#include <bits/stdc++.h>
using namespace std;
int n, p, k;
int main() {
  cin >> n >> p >> k;
  int l = p - k;
  if (l > 1) {
    cout << "<< ";
  }
  if (l <= 0) {
    for (int i = 1; i < p; i++) {
      cout << i << " ";
    }
  } else {
    for (int i = p - k; i < p; i++) {
      cout << i << " ";
    }
  }
  cout << "(" << p << ") ";
  int r = p + k;
  if (r >= n) {
    for (int i = p + 1; i <= n; i++) {
      cout << i << " ";
    }
  } else {
    for (int i = p + 1; i <= p + k; i++) {
      cout << i << " ";
    }
    cout << ">> ";
  }
}
