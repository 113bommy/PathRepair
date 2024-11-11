#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m, n, i, j, ch = 0, ca = 0, b = 0, k, l, p;
  cin >> n;
  long long int arr[n], h[100001], a[100001] = {0};
  for (i = 0; i < n; i++) {
    cin >> p >> b;
    arr[i] = b;
    h[p]++;
    a[b]++;
  }
  for (i = 0; i < n; i++) {
    ch = (n - 1) + h[arr[i]];
    ca = (n - 1) - h[arr[i]];
    cout << ch << " " << ca << endl;
  }
}
