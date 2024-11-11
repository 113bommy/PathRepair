#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[100009];
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int min = sum;
  int ind = 1;
  for (int i = 0; i < k; ++i) {
    int temp = 0;
    int l = i;
    for (int j = 0; j < n / k; j++) {
      temp += a[l];
      l += k;
    }
    if (temp < min) {
      min = temp;
      ind = i + 1;
    }
  }
  cout << ind;
}
