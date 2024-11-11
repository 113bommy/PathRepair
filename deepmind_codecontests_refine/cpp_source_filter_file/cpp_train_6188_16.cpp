#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  long long x[100005];
  cin >> n >> a >> b;
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
    x[i] = x[i] % b / a;
  }
  for (long long int i = 0; i < n - 1; i++) {
    cout << x[i] << ' ';
  }
  cout << x[n - 1] << endl;
  return 0;
}
