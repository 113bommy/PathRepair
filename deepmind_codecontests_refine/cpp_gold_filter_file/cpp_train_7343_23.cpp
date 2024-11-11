#include <bits/stdc++.h>
using namespace std;
void bubble(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (arr[j] > arr[j + 1]) {
        cout << j + 1 << " " << j + 2 << "\n";
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}
int main() {
  int n, i;
  int ar[105];
  cin >> n;
  for (i = 0; i < n; i++) cin >> ar[i];
  bubble(ar, n);
  return 0;
}
