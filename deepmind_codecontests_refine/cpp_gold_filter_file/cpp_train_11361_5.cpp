#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cout << char(i % k + 'a');
    cout << endl;
  }
  return 0;
}
