#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, n, x, H;
  x = 0;
  n = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> H;
    if (n <= H) {
      x++;
      n = H;
    }
  }
  cout << x << endl;
}
