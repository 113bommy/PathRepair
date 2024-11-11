#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) { return x > y; }
int main() {
  int n;
  cin >> n;
  short A[n];
  A[n] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int c = 0;
  while (A[c] != 0) {
    ++c;
  }
  --c;
  sort(A, A + c, cmp);
  short B[n];
  for (int i = 0; i < n + 1; ++i) {
    B[i] = 0;
  }
  int I, C = 0, F = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] == 4) {
      I = C;
      while (B[I] != 0) {
        ++I;
      }
      ++C;
      B[I] += 4;
    } else if (A[i] == 3) {
      I = C + F;
      while (B[I] > 1) {
        ++I;
      }
      ++F;
      B[I] += 3;
    } else if (A[i] == 2) {
      I = C;
      while (B[I] > 2) {
        ++I;
      }
      B[I] = B[I] + 2;
    } else if (A[i] == 1) {
      I = C;
      while (B[I] == 4) {
        ++C;
        ++I;
      }
      B[I] += 1;
    }
  }
  c = 0;
  while (B[c] != 0) {
    ++c;
  }
  cout << c << endl;
}
