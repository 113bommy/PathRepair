#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long ans[200000];
long long x, n, a[200000], b[200000];
long long d, ps[200000], temp;
long long rem;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  long i;
  for (i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> d >> x;
  initAB();
  if (d > 200) {
    for (int i = 0; i < n; i++) ps[a[i] - 1] = i;
    for (int i = 0; i < n; i++) {
      for (int j = n - 1;; --j) {
        temp = ps[j];
        rem = i - temp;
        if (rem >= 0 && rem < n && b[rem] == 1) {
          ans[i] = j + 1;
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++)
      if (b[i]) v.push_back(i);
    for (int i = 0; i < v.size(); i++)
      for (int j = 0; j < n; j++)
        if (v[i] <= j) ans[j] = max(ans[j], a[j - v[i]]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  cin.get();
  cin.get();
  return 0;
}
