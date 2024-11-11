#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, const vector<T>& data) {
  out << "[";
  for (int i = 0; i < data.size(); ++i)
    out << data[i] << (i == data.size() - 1 ? "" : ",");
  out << "]";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const set<T>& s) {
  out << "{";
  for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
    out << *itr << " ";
  out << "}";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const multiset<T>& s) {
  out << "{";
  for (typename multiset<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
    out << *itr << " ";
  out << "}";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  out << "(" << p.first << "," << p.second << ")";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, const map<T1, T2>& m) {
  for (typename map<T1, T2>::const_iterator itr = m.begin(); itr != m.end();
       ++itr)
    out << itr->first << "->" << itr->second << " ";
  return out;
}
const long long INF = 2000000000000000000LL;
const double dINF = INF;
long long N, K;
vector<pair<long long, long long> > segs;
vector<long long> lucks;
vector<long long> moveRto;
vector<long long> moveLto;
long long minRange;
void gen(int len, long long now) {
  if (len >= 19) return;
  if (len > 0) lucks.push_back(now);
  gen(len + 1, now * 10 + 4);
  gen(len + 1, now * 10 + 7);
}
void init() {
  gen(0, 0);
  lucks.push_back(4444444444444444444LL);
  sort(lucks.begin(), lucks.end());
  moveRto.resize(lucks.size());
  moveLto.resize(lucks.size());
  minRange = INF;
  cin >> N >> K;
  segs.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> segs[i].first >> segs[i].second;
    minRange = min(minRange, segs[i].second - segs[i].first + 1);
  }
  vector<pair<long long, int> > s;
  for (int i = 0; i < lucks.size(); ++i) s.push_back(make_pair(lucks[i], -i));
  for (int i = 0; i < N; ++i) {
    s.push_back(make_pair(segs[i].first, 1));
    s.push_back(make_pair(segs[i].second, 2));
  }
  sort(s.begin(), s.end());
  long long last = -1;
  long long cnt = 0;
  long long now = 0;
  double dnow = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (last >= 0) {
      dnow += ((double)(s[i].first - last)) * cnt;
      if (dnow > dINF)
        now = INF;
      else
        now += (s[i].first - last) * cnt;
    }
    if (s[i].second <= 0) moveRto[-s[i].second] = now;
    if (s[i].second == 2) cnt++;
    last = s[i].first;
  }
  last = -1;
  cnt = 0;
  now = 0;
  dnow = 0;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (last >= 0) {
      dnow += ((double)(last - s[i].first)) * cnt;
      if (dnow > dINF)
        now = INF;
      else
        now += (last - s[i].first) * cnt;
    }
    if (s[i].second <= 0) moveLto[-s[i].second] = now;
    if (s[i].second == 1) cnt++;
    last = s[i].first;
  }
}
bool isOK(int l, int r) {
  long long nowRange = lucks[r] - lucks[l] + 1;
  if (nowRange > minRange) return false;
  long long cost = moveRto[r] + moveLto[l];
  return cost <= K;
}
int ans;
void york() {
  ans = 0;
  for (int i = 0; i < lucks.size(); ++i) {
    int l = i;
    int r = (int)lucks.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2 + 1;
      if (isOK(i, mid))
        l = mid;
      else
        r = mid - 1;
    }
    if (isOK(i, l)) ans = max(ans, l - i + 1);
  }
  cout << ans << endl;
}
int main() {
  init();
  york();
  return 0;
}
