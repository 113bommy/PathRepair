#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, arr[100001], b[100001] = {0}, temp, ans, maxright = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  b[n - 1] = arr[n - 1];
  maxright = arr[n - 1];
  for (i = n - 2; i >= 0; i--) {
    temp = arr[i];
    b[i] = maxright;
    if (maxright < temp) {
      maxright = temp;
    }
  }
  for (i = 0; i < n; i++) {
    if (b[i] - arr[i] > 0)
      b[i] = b[i] - arr[i] + 1;
    else
      b[i] = 0;
  }
  b[n - 1] = 0;
  for (i = 0; i < n - 1; i++) {
    cout << b[i] << " ";
  }
  cout << b[n - 1] << endl;
  return 0;
}
