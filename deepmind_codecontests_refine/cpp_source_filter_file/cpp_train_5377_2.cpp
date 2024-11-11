#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, cnt, check, k = 0;
  cin >> n;
  for (int i = 1; i <= (n / 2) + 1; i++) {
    cnt = n - 1;
    if (cnt % i == 0) {
      k++;
    }
  }
  cout << k;
  return 0;
}
