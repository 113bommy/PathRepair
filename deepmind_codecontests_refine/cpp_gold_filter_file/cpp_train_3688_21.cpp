#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int arr[n - 1];
  for (long long int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }
  long long int a, b;
  cin >> a >> b;
  long long int aditi = 0;
  for (long long int i = a - 1; i < b - 1; i++) {
    aditi = aditi + arr[i];
  }
  cout << aditi;
}
