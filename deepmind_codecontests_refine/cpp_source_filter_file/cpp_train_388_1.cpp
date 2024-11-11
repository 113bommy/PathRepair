#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int arr[a];
  for (int x = 0; x < a; x++) {
    cin >> arr[x];
  }
  sort(arr, arr + a);
  int ans1 = 0;
  int y = 1;
  int ans2 = 0;
  for (int x = 0; x < a / 2; x++) {
    ans1 += abs(arr[x] - y);
    y += 2;
  }
  y = 2;
  for (int x = 0; x < a / 2; x++) {
    ans2 += abs(arr[x] - y);
    y += 2;
  }
  cout << min(ans1, ans2);
}
