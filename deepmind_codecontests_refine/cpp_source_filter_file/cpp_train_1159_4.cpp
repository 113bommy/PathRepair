#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = (0); i < (n); i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n / 2 != 0) {
    for (int i = 0; i <= n - 1; i = i + 2) {
      cout << a[i] << " ";
    }
    for (int i = n - 2; i >= 1; i = i - 2) {
      cout << a[i] << " ";
    }
  } else {
    for (int i = 0; i <= n - 2; i = i + 2) {
      cout << a[i] << " ";
    }
    for (int i = n - 1; i >= 1; i = i - 2) {
      cout << a[i] << " ";
    }
  }
}
