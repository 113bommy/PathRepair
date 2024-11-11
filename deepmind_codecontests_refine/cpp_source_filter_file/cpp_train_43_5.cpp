#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long sum;
  long long count = 0;
  if (a / 2 + b + 2 * c >= n)
    for (int i = 0; i <= a; i += 2)
      for (int j = 0; j <= b; j++) {
        sum = n - (i * 1 / 2 + j);
        if (sum < 0 || sum & 1) break;
        if (sum <= 2 * c) {
          count++;
        }
      }
  cout << count;
}
