#include <bits/stdc++.h>
using namespace std;
long long a[123456];
long long Left[123456];
long long Right[123456];
long long odd[123456];
long long Dg(long long k) {
  if (k % 2)
    return k - 1;
  else
    return k;
}
long long Odd(long long k) {
  if (k % 2)
    return k;
  else
    return k - 1;
}
int result[123456];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      Left[i] = 0;
      continue;
    }
    if (a[i - 1] == 1)
      Left[i] = 0;
    else
      Left[i] = Left[i - 1] + Dg(a[i - 1]);
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      Right[i] = 0;
      continue;
    }
    if (a[i] == 1)
      Right[i] = 0;
    else
      Right[i] = Right[i + 1] + Dg(a[i]);
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0)
      odd[i] = 0;
    else
      odd[i] = sum;
    sum += Odd(a[i]);
  }
  long long MaxL = Left[0] - odd[0];
  long long MaxR = Right[0] + odd[0];
  for (int j = 0; j < n; ++j) {
    if (MaxL < Left[j] - odd[j]) {
      MaxL = Left[j] - odd[j];
    }
    result[j] = MaxL + Right[j] + odd[j];
  }
  cout << *(max_element(result, result + n));
  return 0;
}
