#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1000000000")
static int m1[50001][26];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  cout << "2\n";
  for (long long i = 1; i < n; ++i) {
    cout << (i + 2) * (i + 2) * (i + 1) - i << '\n';
  }
  return 0;
}
