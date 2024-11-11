#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  long long int m;
  cin >> n >> m;
  long long int a[n];
  long long int b[m];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int j = 0; j < m; j++) {
    cin >> b[j];
  }
  sort(a, a + n);
  sort(b, b + m);
  long long int temp = a[0] * b[0];
  long long int first_index = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (a[i] * b[j] > temp) {
        first_index = i;
        temp = a[i] * b[j];
      }
    }
  }
  long long int second_index = 0;
  temp = -1000000000000;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (i != first_index && a[i] * b[j] > temp) {
        second_index = j;
        temp = a[i] * b[j];
      }
    }
  }
  cout << temp << '\n';
  return 0;
}
