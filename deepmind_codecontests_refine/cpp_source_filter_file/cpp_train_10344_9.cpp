#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x;
  cin >> n;
  map<long long, long long> mo;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    mo[x] = i;
  }
  long m, ctr1 = 0, ctr2 = 0;
  cin >> m;
  for (long i = 0; i < m; i++) {
    int p;
    cin >> p;
    ctr1 += mo[p] + 1;
    ctr2 += n - mo[p];
  }
  cout << ctr1 << " " << ctr2 << endl;
}
int main() { solve(); }
