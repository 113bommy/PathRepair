#include <bits/stdc++.h>
using namespace std;
int N;
long long F1, F2, F3;
int main() {
  cin >> N;
  N = N / 2 - 1;
  F1 = 1;
  F2 = F1 << 1;
  F3 = F2 << 1;
  while (N--) {
    F3 = F3 * F1 % 1000000009;
    F2 = (F2 + F3) % 1000000009;
    F1 = (F1 * 2 + 3) % 1000000009;
  }
  F2 = (F2 * F2 * 2 + 2) % 1000000009;
  cout << F2 << endl;
  return 0;
}
