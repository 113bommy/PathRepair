#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  int arr[100012];
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long lower = 0;
  int higher = 3;
  long long kount = 0;
  arr[n] = 1e9 + 7;
  for (long long i = 0; i < n; i++) {
    while (arr[higher] - arr[i] <= d && higher < n) higher++;
    kount = kount + (higher - i - 1) * (higher - i - 2) / 2;
  }
  cout << kount << endl;
}
