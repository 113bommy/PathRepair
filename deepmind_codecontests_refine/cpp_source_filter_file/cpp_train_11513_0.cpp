#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cout << (char)((i + 'a') % k);
  }
  return 0;
}
