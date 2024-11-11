#include <bits/stdc++.h>
using namespace std;
int main() {
  int counter = 0;
  double a, b, m, n;
  int i;
  double maxi = 0;
  double shit;
  cin >> n >> m;
  if (m > n) {
    maxi = m;
  } else if (n >= m) {
    maxi = n;
  }
  for (b = 0; b <= maxi; b++) {
    a = n - b;
    a = sqrt(a);
    shit = pow(b, 2);
    if (a + shit == m) {
      counter++;
    }
  }
  cout << counter;
  return 0;
}
