#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1100];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n - 1);
  int left = 1;
  int right = n - 1;
  cout << arr[0];
  while (left <= right) {
    cout << " " << arr[right];
    right--;
    if (left > right) break;
    cout << " " << arr[left];
    left++;
  }
  cout << endl;
}
