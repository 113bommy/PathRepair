#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int main() {
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; ++i) cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; ++i) cout << i + 1 << " ";
    cout << endl;
    for (int i = 0; i < n; ++i) cout << (2 * i + 1) % n << " ";
    cout << endl;
  } else
    cout << "-1";
}
