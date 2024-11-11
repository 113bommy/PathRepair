#include <bits/stdc++.h>
using namespace std;
void solve() {}
int main() {
  long long s;
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long cnt[11]{0};
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  s = (n * n - 1) / 2;
  for (int i = 1; i <= k; i++) s -= (cnt[i] * (cnt[i] - 1)) / 2;
  cout << s << endl;
}
