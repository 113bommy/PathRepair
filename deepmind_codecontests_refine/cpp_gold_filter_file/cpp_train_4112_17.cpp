#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int ans = 0;
  long long int arr[10] = {0,     9,      99,      999,      9999,
                           99999, 999999, 9999999, 99999999, 999999999};
  long long int N;
  cin >> N;
  int i;
  for (i = 0; i < 10; i++) {
    if (N < arr[i]) break;
  }
  int j;
  for (j = 1; j < i; j++) ans += (j) * (arr[j] - arr[j - 1]);
  ans += j * (N - arr[i - 1]);
  cout << ans;
  return 0;
}
