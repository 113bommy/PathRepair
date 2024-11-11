#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k[n], x[n];
  for (int i = 0; i < n; i++) cin >> k[i] >> x[i];
  for (int i = 0; i < n; i++) cout << 9 * k[i] + x[i] - 9 << endl;
}
