#include <bits/stdc++.h>
using namespace std;
int N[101];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    N[t]++;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += N[i] / 2;
  }
  cout << sum / 2;
  return 0;
}
