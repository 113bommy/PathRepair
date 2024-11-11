#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b & 1) return a * power(a, b - 1);
  long long int temp = power(a, b / 2);
  return temp * temp;
}
long long int mycompare(long long int a, long long int b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, r;
    cin >> n >> r;
    if (n > r)
      cout << (r * (r + 1)) / 2;
    else
      cout << (n * (n + 1)) / 2 + 1;
    cout << "\n";
  }
}
