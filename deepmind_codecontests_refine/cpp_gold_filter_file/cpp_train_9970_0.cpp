#include <bits/stdc++.h>
using namespace std;
long long n, a[] = {4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  cin >> n;
  if (n <= 11)
    cout << a[n - 1];
  else
    cout << a[10] + 49 * (n - 11);
  return 0;
}
