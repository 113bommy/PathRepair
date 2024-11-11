#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    cout << m;
  } else if (n == 2) {
    int q = m % 4;
    int p = m / 4;
    int res = p * 4;
    if (q == 1) res += 2;
    if (q == 2) res += 4;
    cout << res;
  } else {
    cout << (n * m + 1) / 2;
  }
  return 0;
}
