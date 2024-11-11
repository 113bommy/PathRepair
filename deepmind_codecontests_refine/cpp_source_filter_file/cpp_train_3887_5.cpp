#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, sum1 = 0, count = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  sum = sum / 2;
  sort(a, a + 1);
  for (int j = n - 1; j >= 0; j--) {
    sum1 = sum1 + a[j];
    count++;
    if (sum < sum1) break;
  }
  cout << count << endl;
  return 0;
}
