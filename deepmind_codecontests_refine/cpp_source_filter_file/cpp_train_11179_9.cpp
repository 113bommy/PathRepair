#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000;
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > res(n, vector<int>(k));
  for (int i = 0; i < k; ++i) {
    int a = 1 << i;
    for (int j = 0; j < n; ++j) {
      if (j <= a) continue;
      if (a + a <= j)
        res[j][i] = j;
      else
        res[j][i] = a + a - j;
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << n - res[n - j - 1][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
