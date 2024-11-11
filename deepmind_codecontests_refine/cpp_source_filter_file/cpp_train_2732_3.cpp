#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 2e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
const long long SQ = 730;
long long p[N];
vector<long long> V;
long long mk[N];
vector<vector<long long>> Q;
long long II = 1e9;
long long wh(long long x) {
  long long res = 1;
  while (res * x < II) res *= x;
  return res;
}
long long hm(long long x, long long p) {
  if (p == 1) return 0;
  long long cnt = 0;
  while (x % p == 0) {
    cnt++;
    x /= p;
  }
  return cnt;
}
long long X;
long long Main() {
  vector<long long> first;
  long long res;
  for (auto &T : Q) {
    long long rs = 1;
    for (auto x : T) rs *= x;
    cout << "? " << rs << endl;
    cin >> res;
    for (auto x : T)
      if (res % x == 0) first.push_back(x);
  }
  if (first.size() == 0) {
    cout << "! 8" << endl;
    return 0;
  }
  long long u = first.size();
  if (u % 2 == 1) {
    first.push_back(1);
    u++;
  }
  long long cnt = 1;
  for (int i = 0; i < u; i += 2) {
    long long Q = wh(first[i]);
    if (first[i + 1] != 1) Q *= wh(first[i + 1]);
    cout << "? " << Q << endl;
    cin >> res;
    cnt *= hm(res, first[i]);
    cnt *= hm(res, first[i + 1]);
  }
  cout << "! " << max(cnt + 7, cnt + cnt) << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i) p[j] = 1;
    if (i < SQ && p[i] == 0) V.push_back(i);
  }
  long long k = V.size();
  long long I = 1e18;
  long long c = 0;
  vector<long long> T;
  for (int i = k - 1; i >= 0; i--) {
    if (mk[i] == 1) continue;
    long long rs = V[i];
    mk[i] = 1;
    T.clear();
    T.push_back(V[i]);
    c++;
    for (int j = i - 1; j >= 0; j--) {
      if (I / rs >= V[j] && mk[j] == 0) {
        mk[j] = 1;
        rs *= V[j];
        T.push_back(V[j]);
      }
    }
    Q.push_back(T);
  }
  long long tc;
  cin >> tc;
  while (tc--) Main();
  return 0;
}
