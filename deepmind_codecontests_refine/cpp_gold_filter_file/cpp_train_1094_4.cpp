#include <bits/stdc++.h>
using namespace std;
long long n, lis[200005], s, cnt, l, r, ansl, ansr, ansp;
long double res;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> lis[i];
  sort(lis, lis + n);
  if (n < 3) {
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << lis[i] << ' ';
    return 0;
  }
  l = 0;
  r = n - 1;
  ansl = l;
  ansr = r;
  cnt = 3;
  ansp = 1;
  s = lis[0] + lis[1] + lis[r];
  res = 1.0 * s / cnt - lis[1];
  for (int pivot = 2; pivot < n - 1; pivot++) {
    s += lis[pivot] - lis[l];
    l++;
    if (r - 1 > pivot && (lis[r - 1] + lis[l - 1]) * cnt > 2 * s) {
      r--;
      l--;
      cnt += 2;
      s += lis[r] + lis[l];
    }
    if (1.0 * s / cnt - lis[pivot] > res) {
      res = 1.0 * s / cnt - lis[pivot];
      ansp = pivot;
      ansl = l;
      ansr = r;
    }
  }
  if (res < 0) {
    cout << 1 << endl << lis[0];
    return 0;
  }
  cout << n - ansr + ansp + 1 - ansl << endl;
  for (int i = ansl; i < ansp + 1; i++) cout << lis[i] << ' ';
  for (int i = ansr; i < n; i++) cout << lis[i] << ' ';
}
