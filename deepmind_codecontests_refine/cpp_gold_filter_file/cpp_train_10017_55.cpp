#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i, cookiesTotal = 0, answer = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    cookiesTotal += a[i];
  }
  int j;
  for (j = 0; j < n; j++) {
    if ((cookiesTotal - a[j]) % 2 == 0) {
      answer++;
    }
  }
  cout << answer;
  return 0;
}
