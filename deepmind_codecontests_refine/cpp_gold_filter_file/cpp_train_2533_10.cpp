#include <bits/stdc++.h>
using namespace std;
int findMax(int &count, int n) {
  int max = -1;
  for (int i = 1; i < n; i++) {
    if (n % i == 0 && i > max) {
      max = i;
      count++;
    }
  }
  if (n / max > max) max = n / max;
  return max;
}
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  sum += n;
  int count = 0;
  while (true) {
    count = 0;
    n = findMax(count, n);
    if (count != 1) {
      sum += n;
    } else {
      break;
    }
  }
  cout << sum + 1 << endl;
  return 0;
}
