#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n - 1; i++) cin >> arr[i];
  int a, b;
  cin >> a >> b;
  int sum = 0;
  for (int i = a - 1; i < b - 1; i++) sum += arr[i];
  cout << sum << endl;
}
