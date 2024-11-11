#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, pos, count = 0, countr = 0;
  cin >> n;
  int arr[n];
  for (int i = 1; i <= n; i++) {
    cin >> pos;
    arr[pos] = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> pos;
    count += arr[pos];
    countr += (n - (arr[pos] - 1));
  }
  cout << count << " " << countr << endl;
  return 0;
}
