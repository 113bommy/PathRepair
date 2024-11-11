#include <bits/stdc++.h>
using namespace std;
long long n, h[100000];
bool first(long long k) {
  bool was[100000];
  int i;
  for (i = 0; i < n; i++) was[i] = true;
  i = 0;
  while (i < n) {
    long long j = max((long long)0, k - h[i] + 1);
    if (j == 0) i++;
    while ((i < n) && (j > 0)) {
      was[i] = false;
      i++;
      j--;
      j = max(j, k - h[i] + 1);
    }
  }
  i = n - 1;
  while (i >= 0) {
    long long j = max((long long)0, k - h[i] + 1);
    if (j == 0) i--;
    while ((i >= 0) && (j > 0)) {
      was[i] = false;
      i--;
      j--;
      j = max(j, k - h[i] + 1);
    }
  }
  bool b = false;
  for (int i = 0; i < n; i++) b = b || ((was[i]) && (i >= k) && (i < n - k));
  return b;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i];
  long long l = 1, r = n + 1;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    if (first(m))
      l = m;
    else
      r = m;
  }
  cout << l + 1;
  return 0;
}
