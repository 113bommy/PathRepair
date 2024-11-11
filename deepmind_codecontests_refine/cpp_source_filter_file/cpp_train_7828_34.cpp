#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  int a[107] = {0};
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= n; ++i) sum += a[i];
  cout << sum / 4;
}
