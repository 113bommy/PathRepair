#include <bits/stdc++.h>
using namespace std;
long long int n, arr[100000];
int main() {
  cin >> n;
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n / 2; i++) {
    if ((i + 1) % 2 != 0) {
      swap(arr[i], arr[n - i - 1]);
    }
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    cout << arr[i] << " ";
  }
  return 0;
  system("pause");
}
