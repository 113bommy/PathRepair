#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b[101];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    b[a] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
}
