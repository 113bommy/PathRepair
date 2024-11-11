#include <bits/stdc++.h>
using namespace std;
const long long MXN = 1e5 + 10;
const long long SQR = 600;
const long long MXM = MXN / SQR + 10;
long long n, q, lastans, indx;
long long A[MXN], Cnt[MXM][MXN];
deque<long long> dq[MXM], Cop;
inline void Add(long long t, long long x, bool f) {
  Cnt[t][x]++;
  if (f)
    dq[t].push_back(x);
  else
    dq[t].push_front(x);
}
inline long long Rmv(long long t, bool f) {
  long long ans;
  Cnt[t][(ans = (f ? dq[t].back() : dq[t].front()))]--;
  if (f)
    dq[t].pop_back();
  else
    dq[t].pop_front();
  return ans;
}
inline long long Get(long long l, long long r, long long k) {
  long long ans = 0;
  for (int t = 0; t <= indx; t++) {
    long long s = max(t * SQR, 1ll), e = min((t + 1) * SQR - 1, n);
    if (e < l || s > r) continue;
    if (l <= s && e <= r) {
      ans += Cnt[t][k];
      continue;
    }
    for (int i = s; i <= e; i++) {
      ans += (dq[t][i - s] == k) * (l <= i && i <= r);
    }
  }
  return ans;
}
inline void Print() {
  for (int t = 0; t <= indx; t++) {
    for (int i = 0; i < dq[t].size(); i++) cout << dq[t][i] << ' ';
    cout << ' ';
  }
  cout << '\n';
}
inline void Shift(long long l, long long r) {
  long long last, fir = l / SQR, lst = r / SQR;
  long long pass = l - max(fir * SQR, 1ll),
            val = dq[lst][r - max(lst * SQR, 1ll)];
  last = Rmv(fir, 1);
  for (int t = 0; t <= indx; t++) {
    long long s = max(t * SQR, 1ll), e = min((t + 1) * SQR - 1, n);
    if (e < l || s > r || t == fir || t == lst) continue;
    Add(t, last, 0), last = Rmv(t, 1);
  }
  long long ns = max(lst * SQR, 1ll), ne = min((lst + 1) * SQR - 1, n);
  for (int i = ns; i <= ne; i++) {
    long long now = dq[lst].front();
    dq[lst].pop_front();
    if (i != r) Cop.push_back(now);
  }
  Add(lst, last, 0), Cnt[lst][val]--, Cnt[fir][val]++;
  while (!Cop.empty()) dq[lst].push_back(Cop.front()), Cop.pop_front();
  while (!dq[fir].empty()) Cop.push_back(dq[fir].front()), dq[fir].pop_front();
  while (!Cop.empty()) {
    if (dq[fir].size() == pass) dq[fir].push_back(val);
    dq[fir].push_back(Cop.front()), Cop.pop_front();
  }
  if (dq[fir].size() == pass) dq[fir].push_back(val);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n, indx = n / SQR;
  for (int i = 1; i <= n; i++) cin >> A[i], Add(i / SQR, A[i], 1);
  cin >> q;
  while (q--) {
    long long typ, l, r, k;
    cin >> typ >> l >> r;
    l = ((l + lastans - 1) % n) + 1, r = ((r + lastans - 1) % n) + 1;
    if (l > r) swap(l, r);
    if (typ == 1) {
      Shift(l, r);
      continue;
    }
    cin >> k;
    k = ((k + lastans - 1) % n) + 1;
    cout << (lastans = Get(l, r, k)) << '\n';
  }
  return 0;
}
