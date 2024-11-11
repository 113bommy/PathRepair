#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  long long LXR = l ^ r;
  long long msbPos = log2(LXR) + 1;
  long long maxXOR = (1 << (msbPos)) - 1;
  cout << maxXOR;
}
