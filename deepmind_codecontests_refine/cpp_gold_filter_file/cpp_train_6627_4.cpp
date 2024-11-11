#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long vx[N], vy[N];
unordered_map<long long, long long> mp1, mp2, mp3, mp4;
pair<long long, long long> A[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, n, i, j;
  long long a, b, res = 0;
  cin >> n >> a >> b;
  long long tot = 1e18 + 1;
  long long x;
  for (i = 0; i < n; i++) {
    cin >> x >> vx[i] >> vy[i];
    long long cur1 = vy[i] - a * vx[i];
    if (cur1 < 0)
      mp3[-cur1]++;
    else
      mp1[cur1]++;
    A[i].first = vx[i];
    A[i].second = vy[i];
  }
  for (auto it : mp1) {
    long long num = 1ll * it.second;
    res += (num * (num - 1)) / 2ll;
  }
  for (auto it : mp3) {
    long long num = 1ll * it.second;
    res += (num * (num - 1)) / 2ll;
  }
  sort(A, A + n);
  long long cnt = 1;
  long long tot2 = 0;
  for (i = 0; i < n - 1; i++) {
    if (A[i].first == A[i + 1].first && A[i].second == A[i + 1].second)
      cnt++;
    else {
      if (cnt > 1) {
        tot2 += (cnt * (cnt - 1)) / 2ll;
        cnt = 1;
      }
    }
  }
  if (cnt > 1) {
    tot2 += (cnt * (cnt - 1)) / 2ll;
    cnt = 0;
  }
  cout << 2ll * (res - tot2) << "\n";
  return 0;
}
