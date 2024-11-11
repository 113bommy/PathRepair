#include <bits/stdc++.h>
using namespace std;
long long arr[] = {1, 3, 6, 10, 15, 21, 27, 33, 39, 43, 46, 48};
long long n;
int main(void) {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < 12; i++) arr[i] = arr[i - 1] + arr[i];
  if (n <= 12)
    cout << arr[n];
  else
    cout << arr[11] + (n - 11) * 49 << endl;
  return 0;
}
