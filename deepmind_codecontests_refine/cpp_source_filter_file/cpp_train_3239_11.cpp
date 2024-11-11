#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  int arr[100001] = {0};
  for (int i = 1; i < 100001; i++) {
    arr[i] = arr[i - 1] + i;
  }
  long long min, max;
  if (n <= 2 * m)
    min = 0;
  else
    min = n - (2 * m);
  for (int i = 0; i < 100001; i++) {
    if (m <= arr[i]) {
      n = n - i - 1;
      break;
    }
  }
  if (m == 0) n++;
  cout << min << " " << n;
  return 0;
}
