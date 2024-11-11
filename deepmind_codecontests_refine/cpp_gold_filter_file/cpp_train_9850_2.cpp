#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1001];
set<long long> bs;
bool cando(long long s) {
  set<long long> b;
  for (int i = 0; i < n; i++) b.insert(2 * a[i] - s * i);
  return b.size() == 2;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (cando(2 * a[2] - 2 * a[1])) return cout << "Yes", 0;
  for (long long i = 1; i < n; i++) {
    if (cando(2 * (a[i] - a[0]) / i)) return cout << "Yes", 0;
  }
  cout << "No";
  return 0;
}
