#include <bits/stdc++.h>
using namespace std;
long long n, k, p = 1;
int main() {
  cin >> n >> k;
  if (k == 1)
    cout << n;
  else {
    while (p < n) p = p * 2 + 1;
    cout << p;
  }
}
