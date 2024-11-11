#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a;
  cin >> n >> k;
  int smallest = n + 1;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (k % a == 0) smallest = min(smallest, k / a);
  }
  cout << smallest << endl;
  return 0;
}
