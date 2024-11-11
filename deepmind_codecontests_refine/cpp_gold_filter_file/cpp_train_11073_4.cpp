#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 3) {
    cout << "-1\n";
    return 0;
  }
  for (int i = n; i > 0; i--) cout << i << " ";
  return 0;
}
