#include <bits/stdc++.h>
using namespace std;
long long n, d, x;
int a[100000], b[100000], ra[100000];
vector<int> bs;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  int i;
  for (i = 0; i < n; i = i + 1) a[i] = i + 1;
  for (i = 0; i < n; i = i + 1) swap(a[i], a[getNextX() % (i + 1)]);
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) swap(b[i], b[getNextX() % (i + 1)]);
}
int main() {
  cin >> n >> d >> x;
  initAB();
  for (int i = 0; i < n; ++i) ra[a[i] - 1] = i;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 1) bs.push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    int ci = 0;
    for (int x = n; x >= n - 50 && x >= 1; --x) {
      if (ra[x - 1] <= i && b[i - ra[x - 1]] == 1) {
        ci = x;
        break;
      }
    }
    if (ci == 0) {
      for (int j = 0; j < bs.size() && bs[j] <= i; ++j) {
        int k = bs[j];
        ci = max(ci, a[i - k]);
      }
    }
    cout << ci << "\n";
  }
  return 0;
}
