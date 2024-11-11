#include <bits/stdc++.h>
using namespace std;
bool prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
      while (x % i == 0) x /= i;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 2, 1);
  int col = 0;
  for (int i = 2; i <= n + 1; i++) {
    if (prime(i)) {
      for (int j = i; j <= n + 1; j += i) {
        if (i != j && a[i] == a[j]) {
          a[j] = a[i] + 1;
          col = max(col, a[j]);
        }
      }
    }
  }
  cout << col << endl;
  for (int i = 2; i <= n + 1; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}
