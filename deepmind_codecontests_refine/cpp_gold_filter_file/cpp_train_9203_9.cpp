#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= 4; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + c <= N) {
      cout << i << " " << a << " " << N - a << "\n";
      return 0;
    }
    if (a + d <= N) {
      cout << i << " " << a << " " << N - a << "\n";
      return 0;
    }
    if (b + c <= N) {
      cout << i << " " << b << " " << N - b << "\n";
      return 0;
    }
    if (b + d <= N) {
      cout << i << " " << b << " " << N - b << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
