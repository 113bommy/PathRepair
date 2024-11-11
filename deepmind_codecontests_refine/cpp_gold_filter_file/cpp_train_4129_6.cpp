#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;
bool A[SIZE][SIZE];
int main() {
  int N, M, a, b;
  cin >> N >> M >> a >> b;
  if (M == 1 || (b - a + 1 <= M && a % M <= b % M && a % M) ||
      (a % M == 1 && (b % M == 0 || b == N)))
    cout << 1;
  else if (a % M == 1 || b % M == 0 || b == N ||
           (a % M == b % M + 1 && a % M) || (a % M == 0 && b % M == M - 1) ||
           (b - 1) / M - (a - 1) / M == 1)
    cout << 2;
  else
    cout << 3;
  return 0;
}
