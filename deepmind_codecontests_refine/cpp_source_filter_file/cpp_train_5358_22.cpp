#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, N, k, r, i = 1;
  cin >> A >> B;
  if (A > 0) {
    cout << i << " ";
    i = i + B;
    i++;
    while (A--) {
      cout << i << " ";
      i++;
    }
    i = 1;
    i = i + B;
    while (B--) {
      cout << i << " ";
      i--;
    }
  } else if (A == 0) {
    B++;
    i = i + B;
    while (B--) {
      cout << i << " ";
      i--;
    }
  }
}
