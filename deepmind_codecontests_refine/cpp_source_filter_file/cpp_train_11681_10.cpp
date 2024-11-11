#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;
int N;
vector<pll> f, b, ff, fb, bf, bb;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 3; i <= N; ++i) {
    lli ccw, s;
    cout << "2 1 2 " << i << endl;
    cin >> ccw;
    cout << "1 1 2 " << i << endl;
    cin >> s;
    if (ccw == 1)
      f.emplace_back(s, i);
    else
      b.emplace_back(s, i);
  }
  sort(f.begin(), f.end());
  sort(b.begin(), b.end());
  int fmx = -1, bmx = -1;
  if (f.size()) {
    fmx = f.back().second;
    for (int i = 0; i < f.size() - 1; ++i) {
      lli ccw;
      cout << "2 1 " << fmx << " " << f[i].second << endl;
      cin >> ccw;
      if (ccw == 1)
        ff.emplace_back(f[i].first, f[i].second);
      else
        fb.emplace_back(f[i].first, f[i].second);
    }
  }
  if (b.size()) {
    bmx = b.back().second;
    for (int i = 0; i < b.size() - 1; ++i) {
      lli ccw;
      cout << "2 1 " << bmx << " " << b[i].second << endl;
      cin >> ccw;
      if (ccw == 1)
        bf.emplace_back(b[i].first, b[i].second);
      else
        bb.emplace_back(b[i].first, b[i].second);
    }
  }
  sort(ff.begin(), ff.end());
  sort(fb.begin(), fb.end());
  sort(bf.begin(), bf.end());
  sort(bb.begin(), bb.end());
  cout << "0 1 ";
  for (auto& [s, i] : bb) cout << i << " ";
  if (bmx != -1) cout << bmx << " ";
  reverse(bf.begin(), bf.end());
  for (auto& [s, i] : bf) cout << i << " ";
  cout << "2 ";
  for (auto& [s, i] : fb) cout << i << " ";
  if (fmx != -1) cout << fmx << " ";
  reverse(bf.begin(), bf.end());
  for (auto& [s, i] : ff) cout << i << " ";
}
