#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, i, c = 0, a, b;
  cin >> n;
  long long int arr[1000] = {0};
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    arr[a]++;
    arr[b]++;
  }
  for (i = 0; i < 1000; i++) {
    if (arr[i] == 1) c++;
  }
  cout << c;
  cout << "\n";
}
