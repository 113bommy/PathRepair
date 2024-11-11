#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  if (N > A * B) {
    cout << -1;
    return 0;
  }
  int odd = 1, even = 2;
  for (int i = 0; i < A; ++i) {
    for (int j = 0; j < B; ++j) {
      if ((i + j) % 2 == 0) {
        if (odd > N) {
          cout << 0 << " ";
        } else {
          cout << odd << " ";
        }
        odd += 2;
      } else {
        if (even > N) {
          cout << 0 << " ";
        } else {
          cout << even << " ";
        }
        even += 2;
      }
    }
    cout << "\n";
  }
  return 0;
}
