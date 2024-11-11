#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long n;
  long long count = 0;
  while (t--) {
    cin >> n;
    if (n < 2)
      count = 0;
    else if (n % 2 == 0)
      count = n / 2 + 1;
    else if (n % 2 == 1)
      count = n / 2;
    cout << count << endl;
    count = 0;
  }
}
