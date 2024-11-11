#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  long long facts = 0;
  for (int i = 1; i * i < x; ++i) {
    if (x % i == 0) {
      long long div1 = x / i, div2 = x / div1;
      if (div1 <= n) {
        if (div1 != div2) facts++;
        facts++;
      }
    }
  }
  cout << facts << endl;
  return 0;
}
