#include <bits/stdc++.h>
using namespace std;
int even[100], odd[100];
int main() {
  int n, d, l;
  cin >> n >> d >> l;
  int s = n / 2 + d;
  if (s > l * ((n + 1) / 2)) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n / 2; i++) even[i] = 1;
  int minv = (n + 1) / 2;
  int j = 0;
  while (s < minv) {
    even[j]++;
    if (even[j] > l) {
      cout << -2 << endl;
      return 0;
    }
    j++;
    if (j == n / 2) j = 0;
    s++;
  }
  for (int i = 0; i < (n + 1) / 2; i++) odd[i] = 1;
  int sum = minv;
  j = 0;
  while (sum < s) {
    sum++;
    odd[j]++;
    if (odd[j] > l) {
      cout << -1 << endl;
      return 0;
    }
    j++;
    if (j == (n + 1) / 2) j++;
  }
  for (int i = 0; i < n / 2; i++) cout << odd[i] << " " << even[i] << " ";
  if (n % 2 == 1) cout << odd[n / 2];
  cout << endl;
}
