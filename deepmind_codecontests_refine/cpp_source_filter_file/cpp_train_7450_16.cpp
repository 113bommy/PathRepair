#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i;
  cin >> n >> k;
  for (i = 0; i <= 50; i++) {
    if ((k - (1 << i)) % (1 << (i + 1)) == 0) break;
  }
  cout << i + 1 << endl;
}
