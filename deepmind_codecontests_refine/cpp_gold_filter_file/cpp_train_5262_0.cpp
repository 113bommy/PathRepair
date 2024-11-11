#include <bits/stdc++.h>
using namespace std;
bool isLeap(long long n) {
  return (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0));
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  while (cin >> n) {
    long long day = 0;
    for (long long i = n;; i++) {
      if (isLeap(i))
        day += 366;
      else
        day += 365;
      if (day % 7 == 0 and isLeap(n) == isLeap(i + 1) and n != i + 1) {
        cout << i + 1 << "\n";
        break;
      }
    }
  }
  return 0;
}
