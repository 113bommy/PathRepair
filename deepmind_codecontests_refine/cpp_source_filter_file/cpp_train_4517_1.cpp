#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 1000 * 1000 * 1000 + 10;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < k; ++i) {
    cout << n + 1 - i << " ";
  }
  for (int i = 0; i < n - k + 1; ++i) cout << i + 1 << " ";
  cout << endl;
  return 0;
}
