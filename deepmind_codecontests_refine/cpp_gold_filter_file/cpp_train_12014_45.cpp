#include <bits/stdc++.h>
using namespace std;
long long int arr[1299710] = {0};
int main() {
  int n;
  cin >> n;
  for (long long int i = 2; i <= 1299710; i++) {
    if (arr[i] == 0) {
      long long int j = 2;
      long long int k = j * i;
      while (k < 1299710) {
        arr[k] = -1;
        j++;
        k = j * i;
      }
    }
  }
  long long int p = 2;
  long long int count = 0;
  while (true) {
    if (arr[p] == 0) {
      cout << p << " ";
      count++;
    }
    p++;
    if (count == n) break;
  }
}
