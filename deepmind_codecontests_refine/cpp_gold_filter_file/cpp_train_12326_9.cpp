#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long n, a[101], s = -1000000000000000000, r, c, e, z;
long long calc(int x, int o, int p) {
  e = 2;
  long long sum = 0;
  for (int i = o + 1; i < p; i++)
    if (a[i] > 0) {
      e++;
      sum += a[i];
    }
  sum += x;
  sum += x;
  return sum;
}
int main() {
  cin >> n;
  long long zz;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] == a[j]) {
        z = calc(a[i], i, j);
        if (z > s) {
          s = z;
          r = i;
          c = j;
          zz = e;
        }
      }
  cout << s << " " << n - zz << endl;
  for (int i = 0; i < n; i++) {
    if (i < r || i > c)
      v.push_back(i + 1);
    else {
      if (i == r || i == c) continue;
      if (a[i] <= 0) v.push_back(i + 1);
    }
  }
  for (int i = 0; i < (signed)v.size(); i++) cout << v[i] << " ";
  return 0;
}
