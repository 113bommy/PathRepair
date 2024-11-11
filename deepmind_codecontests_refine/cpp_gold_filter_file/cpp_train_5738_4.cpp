#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 1, c = 0, p = 1;
  cin >> n;
  long long u = n;
  if (n == 1) {
    long long a;
    cin >> a;
    cout << a << endl;
    return 0;
  }
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (arr[n - 1] == 1) {
    for (long long i = 0; i < n - 2; i++) {
      c = c + ((i + 1) * (arr[i] - 1));
      p++;
    }
    c += ((p)*arr[n - 2]);
    c++;
    cout << c << endl;
  } else {
    for (long long i = 0; i < n - 1; i++) {
      c += ((i + 1) * (arr[i] - 1));
      p++;
    }
    c += p * arr[n - 1];
    cout << c << endl;
  }
}
