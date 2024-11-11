#include <bits/stdc++.h>
using namespace std;
long long t;
long long n, m, k;
long long x, y, a, b;
long long sad, sol;
long long maxx, minn;
vector<long long> v;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
      cout << 'a' + (i % b);
    }
    cout << "\n";
  }
  return 0;
}
