#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m[10];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
  }
  sort(m + 1, m + n + 1);
  if (n == 1) {
    cout << m[n];
  } else {
    cout << m[n / 2 + 1];
  }
}
