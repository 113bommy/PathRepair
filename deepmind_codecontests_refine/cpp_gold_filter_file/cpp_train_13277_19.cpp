#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void solve() {}
int main() {
  int n;
  cin >> n;
  int k = n;
  vector<long long> v(n);
  int i = 0;
  while (n--) {
    cin >> v[i++];
  }
  sort(v.begin(), v.end());
  long long j = 0;
  for (i = 0; i < k; i++) {
    j = min(++j, v[i]);
  }
  cout << ++j;
  return 0;
}
