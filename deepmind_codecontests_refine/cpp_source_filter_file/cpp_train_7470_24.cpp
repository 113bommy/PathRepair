#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long L;
  scanf("%d%lld", &n, &L);
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &b[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int rot = 1; rot <= 2; ++rot) {
    for (int i = 0; i < n; ++i) {
      a.push_back(a[i] + L * rot);
      b.push_back(b[i] + L * rot);
    }
  }
  long long low = 0, high = L - 1;
  while (low < high) {
    long long mid = (low + high) / 2;
    int j1 = 0, j2 = 0;
    bool found = 0;
    int mx = INT_MIN;
    for (int i = n; i < 2 * n; ++i) {
      while (b[j1] < a[i] - mid) {
        ++j1;
      }
      while (j2 + 1 < 3 * n && b[j2 + 1] <= a[i] + mid) {
        ++j2;
      }
      mx = max(mx, j1 - i);
      if (j2 - i < mx) {
        found = true;
        break;
      }
    }
    if (found) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  printf("%lld\n", low);
}
