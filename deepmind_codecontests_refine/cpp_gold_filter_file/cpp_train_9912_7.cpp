#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum;
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    long long n, s;
    cin >> n >> s;
    long long* mas = new long long[n];
    long long* sum = new long long[n];
    cin >> mas[0];
    sum[0] = mas[0];
    for (long long i = 1; i < n; i++) {
      cin >> mas[i];
      sum[i] = sum[i - 1] + mas[i];
    }
    long long index = 0;
    long long max = sum[index];
    long long indexmax = 0;
    while (index < n && sum[index] <= s) {
      index++;
    }
    if (index == n) {
      cout << 0 << endl;
    } else {
      for (long long i = 1; i <= index; i++) {
        if (mas[i] > max) {
          max = mas[i];
          indexmax = i;
        }
      }
      cout << indexmax + 1 << endl;
    }
  }
}
