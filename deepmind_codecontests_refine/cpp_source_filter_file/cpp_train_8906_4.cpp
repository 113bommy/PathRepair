#include <bits/stdc++.h>
using namespace std;
long long int a[10000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  if (n < 3)
    cout << 1;
  else if (n < 5)
    cout << 2;
  else {
    long long int a = 1, b = 2, p = 1;
    while (1) {
      if (a + b < n) {
        p++;
        long long int temp = a + b;
        a = b;
        b = temp;
      } else {
        cout << p;
        return 0;
      }
    }
  }
  return 0;
}
