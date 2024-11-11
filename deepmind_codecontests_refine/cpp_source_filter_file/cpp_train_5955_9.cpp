#include <bits/stdc++.h>
using namespace std;
int nTest;
long long n;
long long k;
long long Get(long long block) {
  if (block == 0) {
    return k * (k + 1) / 2;
  }
  long long nxtBlock = block / k;
  long long subBlock = block % k;
  long long x = Get(nxtBlock);
  long long l = nxtBlock * (k * k + 1) + subBlock * k + 1;
  long long h = nxtBlock * (k * k + 1) + subBlock * k + k;
  long long res = (l + h) * k / 2;
  if (x < l) {
    res += k;
  } else if (x <= h) {
    res += x - l;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> nTest;
  for (int iTest = 1; iTest <= nTest; iTest++) {
    cin >> n >> k;
    long long block = (n - 1) / (k * k + 1);
    long long x = Get(block);
    if (x < n) {
      cout << (n - block - 1) + (n - block - 2) / k << "\n";
    } else if (x == n) {
      cout << (block + 1) * (k + 1) << "\n";
    } else {
      cout << (n - block) + (n - block - 1) / k << "\n";
    }
  }
  return 0;
}
