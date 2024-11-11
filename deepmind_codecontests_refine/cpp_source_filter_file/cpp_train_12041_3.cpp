#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265359;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  if (N < 6)
    cout << -1 << "\n";
  else if (N == 6) {
    cout << 1 << " " << 2 << "\n";
    cout << 2 << " " << 3 << "\n";
    cout << 2 << " " << 4 << "\n";
    cout << 3 << " " << 5 << "\n";
    cout << 3 << " " << 6 << "\n";
  } else {
    cout << 1 << " " << 2 << "\n";
    cout << 2 << " " << 3 << "\n";
    cout << 2 << " " << 4 << "\n";
    cout << 2 << " " << 5 << "\n";
    cout << 3 << " " << 6 << "\n";
    cout << 4 << " " << 7 << "\n";
    for (int i = N - 7, j = 8; i > 0; i--, j++) {
      cout << 4 << " " << j << "\n";
    }
  }
  for (int i = 1; i <= N - 1; i++) {
    cout << i << " " << i + 1 << "\n";
  }
  return 0;
}
