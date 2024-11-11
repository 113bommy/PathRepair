#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  cin >> A;
  cin >> B;
  long long int l1 = A.size();
  long long int l2 = B.size();
  long long int ones[l1];
  long long int zeroes[l1];
  long long int loop = l2 - l1 + 1;
  long long int count = 0;
  ones[0] = 0;
  zeroes[0] = 0;
  for (__typeof(0) i = (0); i < (loop); i++) {
    if (B[i] == '1')
      ones[0]++;
    else
      zeroes[0]++;
  }
  long long int j = l2 - l1 + 1;
  for (__typeof(1) i = (1); i < (l1); i++) {
    if (B[j] == B[i]) {
      ones[i] = ones[i - 1];
      zeroes[i] = zeroes[i - 1];
    } else {
      if (B[j] == '1') {
        ones[i] = ones[i - 1] + 1;
        zeroes[i] = zeroes[i - 1] - 1;
      } else {
        ones[i] = ones[i - 1] - 1;
        zeroes[i] = zeroes[i - 1] + 1;
      }
    }
    j++;
  }
  for (__typeof(0) i = (0); i < (l1); i++) {
    if (A[i] == '1')
      count += zeroes[i];
    else
      count += ones[i];
  }
  cout << count << "\n";
  return 0;
}
