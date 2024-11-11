#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << "1 1\n1\n1 1\n1\n1 1\n-" << arr[0] + 2 << "\n";
    return 0;
  }
  cout << "1 1\n" << n - arr[0] << "\n";
  arr[0] = n;
  cout << "2 " << n << "\n";
  for (int i = 1; i < n; i++) {
    cout << (n - 1) * (arr[i] % n) << " ";
    arr[i] += (n - 1) * (arr[i] % n);
  }
  cout << "\n";
  cout << "1 " << n << "\n";
  for (int i = 0; i < n; i++) cout << (-1) * arr[i] << " ";
  return 0;
}
