#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  int sum1, sum2, sum3;
  cout << "? 1 2" << endl;
  fflush(stdout);
  cin >> sum1;
  cout << "? 1 3" << endl;
  fflush(stdout);
  cin >> sum2;
  cout << "? 2 3" << endl;
  fflush(stdout);
  cin >> sum3;
  int bmc = sum1 - sum2;
  int b = (bmc + sum3) / 2;
  int c = sum3 - b;
  int a = sum1 - b;
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  int sum;
  for (int i = 4; i <= n; i++) {
    cout << "? 1 " << i << endl;
    fflush(stdout);
    cin >> sum;
    arr[i - 1] = sum - a;
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  fflush(stdout);
  return 0;
}
