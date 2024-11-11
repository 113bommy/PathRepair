#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int> > v;
int a[1000000 + 1] = {0};
long long int calc(long long int x) {
  long long int temp = x, sum = 1;
  if (x < 10) {
    return x;
  }
  while (temp) {
    if (temp % 10 != 0) {
      sum *= (temp % 10);
    }
    temp /= 10;
  }
  if (a[sum] != 0) {
    return a[sum];
  } else {
    temp = calc(sum);
    a[sum] = temp;
  }
  return a[sum];
}
void filler() {
  v = vector<vector<long long int> >(10);
  for (long long int i = 0; i < 10; i++) {
    a[i] = i;
  }
  for (long long int i = 1; i <= 1e6; i++) {
    long long int x = calc(i);
    v[x].push_back(i);
  }
  for (long long int i = 0; i < 10; i++) {
    sort(v[i].begin(), v[i].end());
  }
}
int main() {
  long long int n, m, k, i, j, x, y, z, c, f, q, l, r;
  filler();
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> l >> r >> k;
    vector<long long int>::iterator u, d;
    u = lower_bound(v[k].begin(), v[k].end(), l);
    d = upper_bound(v[k].begin(), v[k].end(), r);
    cout << d - u << endl;
  }
}
