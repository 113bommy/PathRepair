#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, temp, a[11] = {0}, sum = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    a[temp]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sum += a[i] * a[j];
    }
  }
  cout << sum;
}
