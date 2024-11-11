#include <bits/stdc++.h>
const long long MOD = 1000000007;
using namespace std;
const int N = 10e5 + 10;
int arr[N] = {0};
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int maxc = 1;
  for (int i = 1; i < n; ++i) {
    int ac = a / i;
    int bc = b / (n - i);
    maxc = max(maxc, min(ac, bc));
  }
  for (int i = 1; i < n; ++i) {
    int bc = b / i;
    int ac = a / (n - i);
    maxc = max(maxc, min(ac, bc));
  }
  cout << maxc << endl;
  return 0;
}
