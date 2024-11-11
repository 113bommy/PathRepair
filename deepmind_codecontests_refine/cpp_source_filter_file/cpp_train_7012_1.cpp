#include <bits/stdc++.h>
const long long int N = 1e5 + 1;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int p = 1;
  while (m) {
    p = ((p % 1000000007) * (2ll % 1000000007)) % 1000000007;
    m--;
  }
  long long int pro = 1;
  for (int i = 1; i <= n; i++) {
    pro = ((pro % 1000000007) * (p % 1000000007 - i % 1000000007 + 1000000007) %
           1000000007) %
          1000000007;
  }
  cout << pro << endl;
}
