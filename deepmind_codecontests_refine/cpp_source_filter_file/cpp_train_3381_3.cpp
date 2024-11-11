#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  n = abs(n);
  n += abs(m);
  if (n > k || (k - m) % 2) {
    cout << "No";
  } else
    cout << "Yes";
}
