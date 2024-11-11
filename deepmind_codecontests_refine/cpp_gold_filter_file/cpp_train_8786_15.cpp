#include <bits/stdc++.h>
using namespace std;
int n, dum;
long long x, y;
vector<int> a;
int main() {
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> dum;
    a.push_back(dum);
    sum += dum;
  }
  cin >> x >> y;
  long long sump = 0;
  for (int i = 0; i < n; i++) {
    sump += a[i];
    if ((sump <= y) && (sump >= x) && (sump <= (sum - x)) &&
        (sump >= (sum - y)) && (i + 2 <= n)) {
      cout << i + 2 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
