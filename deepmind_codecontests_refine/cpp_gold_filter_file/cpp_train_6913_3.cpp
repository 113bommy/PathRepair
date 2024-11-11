#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main(void) {
  int k, d;
  cin.sync_with_stdio(false);
  cin >> k >> d;
  if (d == 0) {
    if (k == 1)
      cout << "0\n";
    else
      cout << "No solution\n";
    return 0;
  }
  if (d <= k)
    for (int i = 1; i <= d; i++) arr[i] = 1;
  else
    arr[1] = d;
  for (int i = 1; i <= k; i++) cout << arr[i];
  return 0;
}
