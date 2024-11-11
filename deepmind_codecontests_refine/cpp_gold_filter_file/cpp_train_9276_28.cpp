#include <bits/stdc++.h>
using namespace std;
int main() {
  int ar[105] = {0};
  int n;
  int r;
  cin >> n;
  int tc = n, a;
  while (tc--) {
    cin >> r;
    for (int i = 0; i < r; i++) {
      cin >> a;
      ar[a]++;
    }
  }
  for (int i = 1; i <= 100; i++)
    if (ar[i] == n) cout << i << " ";
}
