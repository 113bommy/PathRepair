#include <bits/stdc++.h>
using namespace std;
int ar[100005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    if (!ar[i]) cout << i << " ", ar[i] = 1;
    if (!ar[i + k] && (i + k <= n)) cout << i + k << " ", ar[i + k] = 1, k -= 2;
    if (k < 0) k = 0;
  }
  return 0;
}
