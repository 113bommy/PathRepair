#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int k = (int)log2(n) + 1;
    long long s = (long long)pow(2, k) - 1;
    long long ss = (n * (n + 1)) / 2;
    cout << ss - 2 * s << endl;
  }
}
