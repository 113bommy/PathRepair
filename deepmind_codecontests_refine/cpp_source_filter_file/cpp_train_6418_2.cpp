#include <bits/stdc++.h>
using namespace std;
int n, k, gi, ha, a, maj;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    maj += a;
  }
  cout << maj;
}
