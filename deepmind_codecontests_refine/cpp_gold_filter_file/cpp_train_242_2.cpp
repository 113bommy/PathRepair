#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << n << endl;
    ;
  } else if (n % 2 != 0) {
    long long int q2 = n * (n - 1) * (n - 2);
    cout << q2 << endl;
  } else if (n % 2 == 0 && n % 3 != 0) {
    long long int q1 = n * (n - 1) * (n - 3);
    cout << q1 << endl;
  } else {
    long long int q3 = (n - 2) * (n - 1) * (n - 3);
    cout << q3 << endl;
  }
}
