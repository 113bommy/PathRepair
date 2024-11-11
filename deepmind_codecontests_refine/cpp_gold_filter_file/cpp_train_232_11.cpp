#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
long long int arr[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << -arr[0] << endl;
    return 0;
  }
  cout << "1 1" << endl;
  cout << -arr[0] << endl;
  arr[0] = 0;
  cout << "2 " << n << endl;
  for (int i = 1; i < n; ++i) {
    cout << arr[i] * (n - 1) << " ";
    arr[i] += (arr[i] * (n - 1));
  }
  cout << endl;
  cout << "1 " << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << -arr[i] << " ";
  }
  cout << endl;
  return 0;
}
