#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, l, p;
  cin >> n >> m >> k >> l;
  long long want = k + l;
  long long need = want / m;
  if (want % m != 0) need++;
  if (want + need * m <= n)
    cout << need;
  else
    cout << -1;
}
