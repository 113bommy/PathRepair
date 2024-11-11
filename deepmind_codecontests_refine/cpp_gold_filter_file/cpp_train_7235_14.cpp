#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int64_t arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int64_t maxx = abs(arr[0]), cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    maxx += abs(arr[i] - arr[i + 1]);
  }
  cout << maxx;
  return 0;
}
