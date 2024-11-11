#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, i, c = 0, a, b;
  cin >> n;
  long long int arr[1005] = {0};
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    arr[a]++;
    arr[b]++;
  }
  for (i = 0; i < 1005; i++) {
    if (arr[i] == 1) c++;
  }
  cout << c;
  cout << "\n";
}
