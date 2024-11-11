#include <bits/stdc++.h>
using namespace std;
int N, A[8];
int main() {
  cin >> N;
  for (int i = 0; i < 7; i++) {
    cin >> A[i];
  }
  for (int i = 0;; i++) {
    N -= A[i % 7];
    if (N <= 0) {
      cout << i % 7 + 1 << endl;
      break;
    }
  }
}
