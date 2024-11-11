#include <bits/stdc++.h>
using namespace std;
long long n, x, a[5005], uc, sum, mux = 0;
vector<long long> myvec;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    sum = 0;
    for (int j = i; j <= n; j++) {
      sum += a[j];
      if ((j - i + 1) * 100 <= sum) mux = max(mux, (long long)(j - i + 1));
    }
  }
  cout << mux;
  return 0;
}
