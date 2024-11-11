#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 1;
  cin >> n;
  long long int* arr = new long long int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] > c) {
      c++;
    }
    if (arr[i] == c) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
