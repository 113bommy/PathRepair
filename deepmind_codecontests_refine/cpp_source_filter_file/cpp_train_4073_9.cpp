#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<long long int, long long int>, long long int> a,
         pair<pair<long long int, long long int>, long long int> b) {
  if (a.first.first != b.first.first)
    return a.first.first < b.first.first;
  else
    return a.first.second < b.first.second;
}
long long int n, m, k1;
long long int re[2 * 100000 + 2];
long long int pre[2 * 100000 + 3];
bool chec(long long int x) {
  long long int s = 0;
  long long int c = 0;
  for (long long int i = n - (x - 1); i <= n; ++i) {
    s += re[i];
    if (s > k1) {
      c++;
      s += re[i];
    }
  }
  if (s != 0) c++;
  return c <= m;
}
void machayenge() {
  cin >> n >> m >> k1;
  for (long long int i = 1; i <= n; ++i) {
    cin >> re[i];
    pre[i] = pre[i - 1] + re[i];
  }
  long long int i = 0;
  long long int j = n;
  while (i < j) {
    long long int mid = (i + j + 1) / 2;
    if (chec(mid)) {
      i = mid;
    } else
      j = mid - 1;
  }
  cout << i;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  machayenge();
  return 0;
}
