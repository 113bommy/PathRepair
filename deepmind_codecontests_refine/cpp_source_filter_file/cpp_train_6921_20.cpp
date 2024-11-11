#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t, t + n);
  long long int sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (sum <= t[i]) {
      count++;
    } else {
      int j = i;
      while (j < n) {
        if (t[j] > sum) {
          long long int temp = t[j];
          t[j] = t[i];
          t[i] = temp;
          count++;
          break;
        }
        j++;
      }
      if (j == n) {
        break;
      }
    }
    sum += t[i];
  }
  cout << count;
}
