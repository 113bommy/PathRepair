#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  long long cnt;
  while (cin >> n >> k) {
    cnt = n * (n - 1) / 2;
    if (cnt > k) {
      for (int i = 0; i < n; i++) cout << i << " " << i << endl;
    } else
      cout << "no solution" << endl;
  }
  return 0;
}
