#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> mas(n);
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  string s;
  cin >> s;
  unsigned long long max = 0, sum = 0;
  unsigned long long sum0 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') sum0 += mas[i];
  }
  if (sum0 > max) max = sum0;
  sum = sum0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      sum -= mas[i];
    } else
      sum += mas[i];
    if (sum > max) max = sum;
  }
  sum = sum0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'B') {
      sum -= mas[i];
    } else
      sum += mas[i];
    if (sum > max) max = sum;
  }
  cout << max;
  return 0;
}
