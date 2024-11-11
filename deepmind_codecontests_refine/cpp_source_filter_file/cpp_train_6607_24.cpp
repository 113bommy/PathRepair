#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n + 1; i++) {
    cout << ((i) % (n + 1) + 1) << " ";
  }
  return 0;
}
