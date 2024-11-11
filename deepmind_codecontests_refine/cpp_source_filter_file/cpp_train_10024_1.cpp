#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, count = 0, max = 0, min = 200, maxi, mini;
  cin >> a;
  int arr[a];
  for (int i = 0; i < a; i++) {
    cin >> arr[i];
    if (arr[i] > max) {
      max = arr[i];
      maxi = i;
    }
    if (arr[i] <= min) {
      min = arr[i];
      mini = i;
    }
  }
  if (maxi > mini) min++;
  cout << maxi + (a - 1) - mini;
}
