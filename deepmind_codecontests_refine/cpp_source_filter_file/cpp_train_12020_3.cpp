#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n % m == 0) {
    int t = n / m;
    int arr[t + 1];
    for (int i = 0; i <= t; i++) {
      long long int c1 = b * i;
      long long int c2 = (n - m * i) * a;
      long long int t1 = c1 + c2;
      arr[i] = t1;
    }
    long long int temp = arr[0];
    for (int i = 0; i < t; i++) {
      if (temp > arr[i]) {
        temp = arr[i];
      }
    }
    cout << temp;
  }
  if (n % m != 0) {
    int t = n / m;
    int arr[t + 2];
    for (int i = 0; i <= t; i++) {
      long long int c1 = b * i;
      long long int c2 = (n - m * i) * a;
      long long int t1 = c1 + c2;
      arr[i] = t1;
    }
    arr[t + 1] = b * (t + 1);
    long long int temp = arr[0];
    for (int i = 0; i < t + 2; i++) {
      if (temp > arr[i]) {
        temp = arr[i];
      }
    }
    cout << temp;
  }
  return 0;
}
