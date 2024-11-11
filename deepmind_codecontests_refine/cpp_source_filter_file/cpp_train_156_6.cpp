#include <bits/stdc++.h>
using namespace std;
int a[100050];
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int p = 1;
  while (k >= p) {
    k -= p;
    p++;
  }
  cout << a[k - 1];
  return 0;
}
