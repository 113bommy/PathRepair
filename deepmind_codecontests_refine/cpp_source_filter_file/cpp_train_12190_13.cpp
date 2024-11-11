#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long x, d;
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    cin >> x >> d;
    ans += x * n;
    if (d >= 0) {
      long long sum = (n - 1) * n / 2;
      sum = sum * d;
      ans += sum;
    } else {
      long long x = n / 2;
      if (n % 2 == 0) {
        x--;
      }
      long long sum = (x - 1) * x / 2;
      sum = sum * d * 2;
      x = 0;
      if (n % 2 == 0) {
        x = n / 2;
      }
      sum += x * d;
      ans += sum;
    }
  }
  long double answer = ans;
  answer = answer / n;
  cout << fixed << setprecision(15) << answer << endl;
}
