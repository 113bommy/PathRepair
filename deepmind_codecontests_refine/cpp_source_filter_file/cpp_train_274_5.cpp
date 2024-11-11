#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, temp, i;
  cin >> n >> k;
  long long int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int count = 0;
  for (i = 0; i < n - 1; i++) {
    long long int j = i + 1;
    long long int cnt = 1;
    while (a[i] == a[j]) {
      j++;
      cnt++;
    }
    if (a[i] + k >= a[j]) {
      count = count + cnt;
    }
    i = j - 1;
  }
  cout << n - count << endl;
  return 0;
}
