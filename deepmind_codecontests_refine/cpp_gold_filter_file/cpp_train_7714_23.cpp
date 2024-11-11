#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  cout << "YES" << endl;
  for (long long i = n; i <= m; i += 2) {
    cout << i << " " << i + 1 << endl;
  }
}
