#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long sum = n;
  while (true) {
    long long cnt = 2;
    while (n % cnt != 0) {
      cnt++;
      if (cnt == (long long)sqrt(n) + 1) {
        cnt = n;
        break;
      }
    }
    n /= cnt;
    sum += n;
    if (n == 1) break;
  }
  cout << sum << endl;
}
