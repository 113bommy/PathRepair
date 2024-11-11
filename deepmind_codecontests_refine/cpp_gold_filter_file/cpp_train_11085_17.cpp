#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, c;
  cin >> a;
  const int b = a;
  int A[b], B[3];
  for (int i = 0; i < 3; i++) {
    B[i] = 0;
  }
  for (int i = 0; i < b; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < b; i++) {
    B[A[i] - 1]++;
  }
  c = 0;
  for (int i = 0; i < 3; i++) {
    if (B[i] > c) {
      c = B[i];
    }
  }
  cout << a - c;
}
