#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = m; i > 0; i -= 1) {
    cout << i << " ";
  }
  for (int i = m + 1; i <= n; i += 1) {
    cout << i << " ";
  }
}
