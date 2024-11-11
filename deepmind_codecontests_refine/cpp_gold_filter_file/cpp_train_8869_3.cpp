#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long N;
  cin >> N;
  map<long long, long long> mp;
  long long a;
  long long mx = 0;
  vector<pair<long long, long long> > vp;
  for (long long i = 0; i < N; i++) {
    cin >> a;
    mp[a]++;
    mx = max(mx, mp[a]);
  }
  for (auto m : mp) {
    vp.emplace_back(m.second, m.first);
  }
  sort(vp.rbegin(), vp.rend());
  long long H;
  long long t = 0;
  long long tot = N;
  for (long long i = N; i >= 1; i--) {
    long long w = min((long long)vp.size(), (tot / i));
    if (i <= vp.size() && w >= i) {
      long long area = i * w;
      if (t < area) {
        t = area;
        H = i;
      }
    }
    for (long long j = 0; j < vp.size(); j++) {
      if (vp[j].first == i) {
        vp[j].first--;
        tot--;
      } else {
        break;
      }
    }
  }
  vp.clear();
  for (auto m : mp) {
    vp.emplace_back(m.second, m.first);
  }
  sort(vp.rbegin(), vp.rend());
  tot = N;
  for (long long i = N; i > H; i--) {
    for (long long j = 0; j < vp.size(); j++) {
      if (vp[j].first == i) {
        vp[j].first--;
        tot--;
      } else {
        break;
      }
    }
  }
  vector<long long> A;
  for (long long i = 0; i < vp.size(); i++) {
    for (long long j = 0; j < vp[i].first; j++) {
      A.push_back(vp[i].second);
    }
  }
  long long W = min((long long)vp.size(), (tot / H));
  vector<vector<long long> > res(H, vector<long long>(W));
  for (long long j = 0; j < W; j++) {
    for (long long i = 0; i < H; i++) {
      res[i][(i + j) % W] = A[j * H + i];
    }
  }
  cout << H * W << endl;
  cout << H << " " << W << endl;
  for (long long i = 0; i < H; i++) {
    for (long long j = 0; j < W; j++) {
      if (j > 0) cout << " ";
      cout << res[i][j];
    }
    cout << endl;
  }
}
