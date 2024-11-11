#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  long long curr = 1;
  for (int i = 0; i < n; i += 2) {
    a[i] = curr;
    curr++;
  }
  curr = n;
  for (int i = 1; i < n; i += 2) {
    a[i] = curr;
    curr--;
  }
  sort(a.begin() + k, a.end());
  if (!(k & 1)) reverse(a.begin() + k, a.end());
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
