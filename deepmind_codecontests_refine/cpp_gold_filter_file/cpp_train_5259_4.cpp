#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5) + 7;
int ar[MAX + 7], x;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x, ar[x] = ar[x - 1] + 1;
  cout << n - *max_element(ar, ar + MAX) << "\n";
  return 0;
}
