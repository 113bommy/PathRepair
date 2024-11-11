#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[51];
long long M = 1000000007;
int main() {
  long long a = 1, b = 1;
  long long n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    a = (a * 27) % M;
    b = (b * 7) % M;
  }
  cout << (a - b) << endl;
  return 0;
}
