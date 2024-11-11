#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  out << "(" << p.first << "," << p.second << ") ";
  return out;
}
template <typename A, typename B>
void printP(const pair<A, B>& p, const char* str = NULL) {
  if (!(1 && !1)) return;
  if (str != NULL) cout << str << ":";
  cout << "(" << p.first << "," << p.second << ") ";
}
template <typename T>
void printV(const vector<T>& v, const char* str = NULL) {
  if (!(1 && !1)) return;
  if (str != NULL) cout << str << ": ";
  for (int i = 0; i < (v.size()); ++i) cout << v[i] << " ";
  cout << '\n';
}
template <typename T>
void printC(T& container, const char* str = NULL) {
  if (!(1 && !1)) return;
  if (str != NULL) cout << str << ":";
  for (__typeof((container).begin()) it = ((container).begin());
       it != (container).end(); ++it) {
    cout << (*it) << " ";
  }
  cout << '\n';
}
const int INF = 1000010111;
const int S_N = 152;
const int MOD = 1000000007;
int cntFree(vector<pair<int, int> >& v, int n, bool s = true) {
  if ((1 && !1)) printf("cntFree(v, %d)\n", n);
  printV(v, "V");
  int sum = 0;
  int last = 0;
  v.push_back(make_pair(n, n));
  if (s) sort((v).begin(), (v).end());
  for (__typeof((v).begin()) it = ((v).begin()); it != (v).end(); ++it) {
    if (it->first > last) sum += (it->first - last);
    last = max(last, it->second);
  }
  return sum;
}
int cut(vector<pair<int, int> >& v, int n, int need) {
  int sum = 0;
  int last = 0;
  v.push_back(make_pair(n, n));
  for (__typeof((v).begin()) it = ((v).begin()); it != (v).end(); ++it) {
    if (it->first > last) sum += (it->first - last);
    if (sum >= need) {
      last = it->first;
      break;
    } else
      last = max(last, it->second);
  }
  if (sum < need) return -1;
  last -= sum - need;
  return last;
}
int grundi(map<int, vector<pair<int, int> > >& M, vector<int>& C, int n,
           int def) {
  if ((1 && !1)) {
    cout << "grundi\nM: ";
    for (__typeof((M).begin()) it = ((M).begin()); it != (M).end(); ++it)
      cout << (it->first) << ", " << (it->second.size()) << " ";
    cout << '\n';
    cout << "C: ";
    for (__typeof((C).begin()) it = ((C).begin()); it != (C).end(); ++it)
      cout << (*it) << " ";
    cout << '\n';
    cout << "N: " << n << ", def: " << def << '\n';
  }
  int g = 0;
  if ((n - 1 - C.size()) % 2 == 1) g = def;
  if ((1 && !1)) {
    cout << "g = " << g << " Csize: " << C.size() << '\n';
  }
  for (__typeof((C).begin()) it = ((C).begin()); it != (C).end(); ++it) {
    int cnt = cntFree(M[*it], def);
    g = g ^ cnt;
    if ((1 && !1)) printf("\n\n\ncnt == %d, g = %d\n", cnt, g);
  }
  return g;
}
int mex(vector<int>& v, int start = 1) {
  for (__typeof((v).begin()) it = ((v).begin()); it != (v).end(); ++it) {
    if (*it != start) return start;
    start++;
  }
  return start;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, vector<pair<int, int> > > X, Y;
  vector<int> CX, CY;
  for (int _ = 0; _ < (k); ++_) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int nr, s, e;
    if (x1 == x2) {
      s = min(y1, y2), e = max(y1, y2);
      if (X[x1].empty()) CX.push_back(x1);
      X[x1].push_back(make_pair(s, e));
    } else {
      s = min(x1, x2), e = max(x1, x2);
      if (Y[y1].empty()) CY.push_back(y1);
      Y[y1].push_back(make_pair(s, e));
    }
  }
  int g = grundi(X, CX, n, m);
  g = g ^ grundi(Y, CY, m, n);
  if (g == 0) {
    cout << "SECOND" << '\n';
  } else {
    cout << "FIRST" << '\n';
    int nr = -1;
    int emp = mex(CX, 1);
    if (emp < n) CX.push_back(emp);
    emp = mex(CY, 1);
    if (emp < m) CY.push_back(emp);
    pair<int, int> p1, p2(-1, -1);
    for (int i = 0; i < CX.size() + CY.size(); i++) {
      bool iks = (i < CX.size());
      int p = iks ? CX[i] : CY[i - CX.size()];
      if ((1 && !1)) printf("i=%d, iks=%d, p=%d\n", i, (int)iks, p);
      int free = cntFree((iks ? X : Y)[p], iks ? m : n, false);
      int free2 = free ^ g;
      if ((1 && !1)) printf("free = %d, free ^ g = %d\n", free, free2);
      if (free2 <= free) {
        int last = cut((iks ? X : Y)[i], m, free - free2);
        if (iks) {
          p1 = make_pair(p, 0), p2 = make_pair(p, last);
        } else {
          p1 = make_pair(0, p), p2 = make_pair(last, p);
        }
        break;
      }
    }
    cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second
         << '\n';
  }
  if ((1 && !1)) {
    cout << g << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
