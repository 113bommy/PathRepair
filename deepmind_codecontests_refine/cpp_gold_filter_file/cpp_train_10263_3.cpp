#include <bits/stdc++.h>
using namespace std;
int main() {
  long long arr[100000], n = 0, c = 0;
  cin >> n;
  int mini = 1000000000, maxi = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] < mini) mini = arr[i];
    if (arr[i] > maxi) maxi = arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] == mini || arr[i] == maxi) continue;
    c++;
  }
  cout << c;
  return 0;
}
