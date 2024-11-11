#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long counts = 0;
  int j = 1;
  for (int i = 0; i < n; i++) {
    counts += abs(j - arr[i]);
    j++;
  }
  cout << counts;
}
