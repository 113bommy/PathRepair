#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  long long i, j, k, n, sum = 0;
  cin >> n;
  long long a = 1, b = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++) cout << "  ";
    for (j = 0; j < i + 1; j++) {
      cout << j;
      if (i != 0) cout << " ";
    }
    j -= 2;
    for (k = 0; k < i; k++) {
      cout << j;
      if (j != 0) cout << " ";
      j--;
    }
    cout << endl;
  }
  for (i = 0; i < n + 1; i++) cout << i << " ";
  for (i = n - 1; i >= 0; i--) {
    cout << i;
    if (i != 0) cout << " ";
  }
  cout << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < i + 1; j++) cout << "  ";
    for (j = 0; j < n - i; j++) {
      cout << j;
      if (i != n) cout << " ";
    }
    j -= 2;
    for (k = 0; k < n - i - 1; k++) {
      cout << j;
      if (k != n - i - 2) cout << " ";
      j--;
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
