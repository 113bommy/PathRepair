#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool found[10000000];
int main() {
  cin >> n >> k;
  memset(found, false, sizeof(found));
  for (int i = 1; i <= min(10000000ll, k); i++) {
    if (found[n % i]) {
      cout << "No\n";
      return 0;
    } else {
      found[n % i] = true;
    }
  }
  cout << "Yes\n";
}
