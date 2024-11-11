#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 200010;
long long arr[N];
int main() {
  cin >> n;
  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    cin >> arr[i];
    if (arr[i] < 0) {
      arr[i] = -arr[i];
      cnt++;
    }
    sum += arr[i];
  }
  sort(arr, arr + 2 * n + 1);
  if (n % 2 == 1)
    cout << sum << endl;
  else {
    if (cnt % 2 == 0)
      cout << sum << endl;
    else
      cout << sum - 2 * arr[0] << endl;
  }
  return 0;
}
