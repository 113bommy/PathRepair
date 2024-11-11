#include <bits/stdc++.h>
using namespace std;
long long arr[2000007];
long long cs[2000007];
long long ps[2000007];
int main() {
  long long n;
  cin >> n;
  long long l = sqrt(n);
  long long maxx = max(1LL, (l - 30));
  for (long long int i = maxx; i <= sqrt(n); i++) {
    long long sum = 0;
    long long j = i;
    while (j) {
      long long rem = j % 10;
      sum += rem;
      j /= 10;
    }
    if ((i * i) + (sum * i) - n == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
