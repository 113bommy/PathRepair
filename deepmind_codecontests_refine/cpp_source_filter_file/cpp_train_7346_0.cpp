#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0, j = 1, a[1000] = {0};
  cin >> n;
  if (n == 1) {
    cout << "1\n1";
    return 0;
  } else {
    while (n > j) {
      a[i] = j;
      n -= j;
      i++;
      j++;
    }
    a[i - 1] += n;
    cout << i << "\n";
    for (j = 0; j < i; j++) cout << a[j] << " ";
    return 0;
  }
}
