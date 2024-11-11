#include <bits/stdc++.h>
using namespace std;
long long power(int x, int y) {
  long long p = 1;
  for (int i = 0; i < y; i++) {
    p *= x;
  }
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> n >> s;
  if (s % 2 == 0 and s < n * 2) {
    cout << "NO";
  } else if (s % 2 == 0 and s >= n * 2) {
    cout << "YES" << '\n';
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << " ";
    }
    cout << s - (n - 1) << '\n';
    cout << s / 2;
  } else if (n % 2 == 1 and s / 2 >= n) {
    cout << "YES" << '\n';
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << " ";
    }
    cout << s - (n - 1) << '\n';
    cout << s / 2;
  } else {
    cout << "NO";
  }
  return 0;
}
