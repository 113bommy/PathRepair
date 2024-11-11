#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[3] = {0}, a, max = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr[a]++;
  }
  for (int i = 1; i <= 3; i++) {
    if (arr[i] > max) max = arr[i];
  }
  cout << n - max << endl;
  return 0;
}
