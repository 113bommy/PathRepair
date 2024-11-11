#include <bits/stdc++.h>
using namespace std;
long long int T, n, in, i, m, j, k;
vector<long long int> a;
vector<long long int>::iterator it;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  long long int r, c;
  if (k < n) {
    r = k + 1;
    c = 1;
  } else {
    k -= n;
    r = n - k / (m - 1);
    c = (k % (m - 1));
    if ((n - r) % 2 == 0)
      c += 2;
    else
      c = m - c;
  }
  cout << r << " " << c;
  return 0;
}
