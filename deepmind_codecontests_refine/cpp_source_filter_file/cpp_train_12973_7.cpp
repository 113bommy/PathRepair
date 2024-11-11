#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a = sqrt(n) + 1;
  if (sqrt(n) == a - 1)
    cout << a * 4 << endl;
  else {
    long long b = a * a - n;
    cout << 2 * a + 2 * (a - (b / a + 1)) + 2 << endl;
  }
}
