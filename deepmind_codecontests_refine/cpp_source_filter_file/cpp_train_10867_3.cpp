#include <bits/stdc++.h>
using namespace std;
const int INF = 1E9 + 7;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> pair) {
  out << "(" << pair.first << ", " << pair.second << ")";
  return out;
}
pair<int, int> p1, pn;
int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
bool comp(const pair<pair<int, int>, int> &l,
          const pair<pair<int, int>, int> &r) {
  return dist(l.first, pn) < dist(r.first, pn);
}
int n, d;
vector<pair<pair<int, int>, int> > t;
int best[105];
bool check(int x) {
  for (int i = (0); i <= (((int)(t).size()) - 1); ++i) {
    if (0) cout << i << " " << t[i].first << endl;
    best[i] = 1 + 2 * x - dist(p1, t[i].first) * d * 2;
  }
  for (int i = (0); i <= (((int)(t).size()) - 1); ++i) {
    if (best[i] > 0)
      for (int j = (i + 1); j <= (((int)(t).size()) - 1); ++j) {
        maxi(best[j],
             best[i] + t[i].second - d * dist(t[i].first, t[j].first) * 2);
      }
  }
  return best[n - 2] > 0;
}
pair<int, int> wczyt() {
  int a, b;
  cin >> a >> b;
  return pair<int, int>(a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> d;
  for (int i = (2); i <= (n - 1); ++i) {
    int a;
    cin >> a;
    t.push_back(make_pair(pair<int, int>(0, 0), 2 * a));
  }
  p1 = wczyt();
  for (int i = (2); i <= (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    t[i - 2].first = pair<int, int>(x, y);
  }
  pn = wczyt();
  sort((t).begin(), (t).end(), comp);
  t.push_back(make_pair(pn, 0));
  {
    if (0)
      cerr << "p1"
           << " = " << p1 << endl;
  };
  {
    if (0)
      cerr << "pn"
           << " = " << pn << endl;
  };
  {
    if (0)
      cerr << "check(1000000)"
           << " = " << check(1000000) << endl;
  };
  int s = 0, e = INF;
  int best = -1;
  while (s <= e) {
    int q = (s + e) / 2;
    if (check(q)) {
      best = q;
      e = q - 1;
    } else
      s = q + 1;
  }
  cout << best << endl;
  return 0;
}
