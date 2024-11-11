#include <bits/stdc++.h>
using namespace std;
int const oo = INT_MAX;
int main() {
  int n;
  cin >> n;
  int v[n][2];
  for (int i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1];
  }
  int c = min(2, n);
  for (int i = 1; i < n - 1; i++) {
    if (v[i][0] - v[i][1] > v[i - 1][0])
      c++;
    else if (v[i][0] + v[i][1] < v[i + 1][0]) {
      c++;
      v[i][0] += v[i][1];
    }
  }
  cout << c;
}
