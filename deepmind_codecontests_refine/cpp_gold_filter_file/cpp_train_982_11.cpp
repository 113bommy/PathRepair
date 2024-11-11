#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
long long exp(long long a, long long b) {
  long long ans = 1;
  while (b != 0) {
    if (b % 2) ans = ans * a;
    a = a * a;
    b /= 2;
  }
  return ans;
}
long long arr[1005][1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, d;
  cin >> n >> k >> d;
  long long tmp = 1;
  bool fg = 0;
  for (long long i = (long long)0; i < (long long)d; i++) {
    tmp = tmp * k;
    if (tmp >= n) {
      fg = 1;
      break;
    }
  }
  if (!fg) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = (long long)1; i < (long long)n + 1; i++) {
    for (long long j = (long long)0; j < (long long)d; j++) {
      arr[i][j] = arr[i - 1][j];
    }
    for (long long j = (long long)0; j < (long long)d; j++) {
      arr[i][j] = (arr[i][j] + 1) % k;
      if (arr[i][j]) break;
    }
  }
  for (long long j = (long long)0; j < (long long)d; j++) {
    for (long long i = (long long)1; i < (long long)n + 1; i++)
      cout << arr[i][j] + 1 << " ";
    cout << endl;
  }
  return 0;
}
