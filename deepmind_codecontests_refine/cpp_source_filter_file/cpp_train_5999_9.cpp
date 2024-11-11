#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, element;
  cin >> n;
  long long arr[n];
  long long maxi = 0;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] >= maxi) maxi = arr[i];
  }
  if (maxi <= 25)
    cout << 0;
  else
    cout << maxi - n;
}
