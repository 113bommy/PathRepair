#include <bits/stdc++.h>
using namespace std;
int v[1000000];
int main() {
  long long d, i, j = 0, n, S = 0;
  cin >> n >> d;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    while (j <= i && v[i] - v[j] > d) {
      j++;
    }
    S += (i - j) * (i - j - 1) / 2;
  }
  cout << S;
  return 0;
}
