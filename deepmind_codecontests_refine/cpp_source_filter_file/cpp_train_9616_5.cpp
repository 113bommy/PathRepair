#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int even = 0, odd = 0, indexi = 0, indexj = 0;
  int i = 0;
  while (i < n) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      indexi = 1;
      even++;
    } else {
      indexj = i;
      odd++;
    }
    i++;
  }
  if (odd == 1)
    cout << indexj + 1;
  else
    cout << indexi + 1;
}
