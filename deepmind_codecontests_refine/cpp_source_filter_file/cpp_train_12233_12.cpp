#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  long long n;
  cin >> n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % (i * i) == 0) {
      n /= i;
      i = 2;
    }
  }
  cout << n << endl;
  return 0;
}
