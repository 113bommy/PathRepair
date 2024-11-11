#include <bits/stdc++.h>
using namespace std;
long long ior(long long i, long long j) {
  cout << "or " << i << " " << j << "\n";
  cout.flush();
  long long ret;
  cin >> ret;
  return ret;
}
long long iand(long long i, long long j) {
  cout << "and " << i << " " << j << "\n";
  cout.flush();
  long long ret;
  cin >> ret;
  return ret;
}
void ifinish(long long n) {
  cout << "finish " << n << "\n";
  cout.flush();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e, f, i, j, k, m, n, o, x, y, z;
  cin >> n >> k;
  x = ior(1, 2) + iand(1, 2);
  y = ior(2, 3) + iand(2, 3);
  z = ior(3, 1) + iand(3, 1);
  a = (z + x - y) / 2;
  b = x - a;
  c = z - a;
  vector<long long> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  for (i = 3; i < n; i++) v.push_back((a ^ ior(1, i)) | iand(1, i));
  sort(v.begin(), v.end());
  ifinish(v[k - 1]);
}
