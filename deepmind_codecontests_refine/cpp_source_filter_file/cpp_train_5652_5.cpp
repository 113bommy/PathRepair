#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x = 0;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    x ^= arr[i];
  }
  if (n % 2 or x == 0) {
    cout << "YES\n";
    long long int num, turn = 2;
    if (n % 2)
      num = n - 1;
    else
      num = n - 2;
    cout << num << endl;
    while (turn--) {
      for (int i = 2; i <= num; i += 2)
        cout << "1 " << i << " " << i + 1 << endl;
    }
  } else
    cout << "N0";
}
