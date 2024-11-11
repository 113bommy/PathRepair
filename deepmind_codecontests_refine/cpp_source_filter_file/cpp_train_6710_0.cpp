#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%1d", &x);
    if (x) {
      count++;
      continue;
    }
    break;
  }
  cout << min(count, n);
  return 0;
}
