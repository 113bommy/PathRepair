#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
long long mod = 1e9 + 7;
long long powm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
long long n, k;
vector<long long> a;
void solve() {
  cin >> n >> k;
  a.resize(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  sort(a.begin(), a.end());
  deque<pair<long long, long long> > freq;
  freq.push_back(make_pair(a[0], 1));
  for (long long i = (1); i < (n); i++) {
    if (a[i - 1] != a[i]) freq.push_back(make_pair(a[i], 0));
    (freq.back()).second++;
  }
  while (freq.size() > 1 and k > 0) {
    pair<long long, long long> fnt = freq.front();
    pair<long long, long long> bck = freq.back();
    if (bck.second > fnt.second) {
      freq.pop_front();
      pair<long long, long long> tmp_f = freq.front();
      long long new_f = min((tmp_f.first - fnt.first), (k / fnt.second));
      k -= new_f * fnt.second;
      if (new_f == 0) {
        cout << bck.first - fnt.first - new_f << endl;
        return;
      }
      if (new_f + fnt.first == tmp_f.first)
        freq.front().second += fnt.second;
      else
        freq.push_front(make_pair(fnt.first + new_f, fnt.second));
    } else {
      freq.pop_back();
      pair<long long, long long> tmp_b = freq.back();
      long long new_b = min((bck.first - tmp_b.first), k / bck.second);
      k -= new_b * bck.second;
      if (new_b == 0) {
        cout << bck.first - fnt.first - new_b << endl;
        return;
      }
      if (bck.first - new_b == tmp_b.first)
        freq.back().second += bck.second;
      else
        freq.push_back(make_pair(bck.first - new_b, bck.second));
    }
  }
  if (freq.size() == 1)
    cout << 0 << endl;
  else
    cout << freq.back().first - freq.front().first << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
