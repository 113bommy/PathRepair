#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n;
char a[maxn];
int main() {
  cin >> n;
  cin >> a;
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != a[i + 1]) {
      i += 2;
      ++res;
    }
  }
  cout << n - res << endl;
}
