#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  cout << (n / (a + b)) + min((n % (a + b)), a);
  return 0;
}
