#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    vector<long long> ans(n);
    long long temp = 2;
    for (long long i = 0; i < n; i++) {
      ans[i] = temp;
      temp *= 2;
    }
    long long m1 = 0;
    long long m2 = 0;
    if (n == 2)
      cout << "2" << endl;
    else {
      m1 += ans[n - 1];
      for (long long i = 0; i < (n / 2) - 1; i++) m1 += ans[i];
      for (long long i = (n / 2); i < (n - 1); i++) m2 += ans[i];
      cout << abs(m1 - m2) << endl;
    }
  }
}
