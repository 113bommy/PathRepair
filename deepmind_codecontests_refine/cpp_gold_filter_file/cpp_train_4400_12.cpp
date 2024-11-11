#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p[n], r[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    r[p[i] - 1] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << r[i] << " ";
  }
  return 0;
}
