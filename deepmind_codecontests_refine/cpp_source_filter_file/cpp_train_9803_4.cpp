#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int arr[100007];
  memset(arr, 0, 100007);
  arr[0] = 1;
  arr[1] = 1;
  long long int c = 1;
  for (long long int i = 0; i < 100007; i++) {
    if (arr[i] == 0) {
      long long int j = 1;
      while (i * j < 100007) {
        if (arr[i * j] == 0) arr[i * j] = c;
        j++;
      }
      c++;
    }
  }
  long long int n;
  cin >> n;
  for (long long int i = 2; i < n + 1; i++) {
    cout << arr[i] << " ";
  }
}
