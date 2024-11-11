#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<int> Tx, Ty;
int lx, ly;
int Stworz(vector<int>& T, int n) {
  int p = 1;
  while (p < n) p *= 2;
  int l = p;
  int size = 2 * p - 1;
  for (int i = 0; i <= size; ++i) T.push_back(-INF);
  return l;
}
void Ustaw(vector<int>& T, int l, int a, int x) {
  a += l;
  T[a] = x;
  a /= 2;
  while (a != 0) {
    T[a] = max(T[2 * a], T[2 * a + 1]);
    a /= 2;
  }
}
int Max(vector<int>& T, int l, int a, int b) {
  a += l;
  b += l;
  int w = max(T[a], T[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) w = max(w, T[a + 1]);
    if (b % 2 == 1) w = max(w, T[b - 1]);
    a /= 2;
    b /= 2;
  }
  return max(w, 0);
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  lx = Stworz(Tx, n);
  ly = Stworz(Ty, n + 9);
  set<pair<int, int> > Sx, Sy;
  for (int i = 0; i < m; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int p, h;
      cin >> p >> h;
      --p;
      pair<int, int> nowy = make_pair(p, h - i);
      vector<pair<int, int> > t;
      while (Sy.begin() != Sy.end() && (*Sy.begin()).first < nowy.second) {
        t.push_back(*Sy.begin());
        swap(t.back().first, t.back().second);
        Sy.erase(Sy.begin());
        Ustaw(Ty, ly, t.back().second + n - 2, -INF);
        Ustaw(Tx, lx, t.back().first, -INF);
      }
      t.push_back(nowy);
      while (t.size() != 0) {
        int lis = Max(Tx, lx, t.back().first, n - 1) + 1;
        swap(t.back().first, t.back().second);
        Sy.insert(t.back());
        swap(t.back().first, t.back().second);
        Ustaw(Ty, ly, t.back().second + n - 2, lis);
        Ustaw(Tx, lx, t.back().first, lis);
        t.pop_back();
      }
      Sx.insert(nowy);
    } else {
      int x;
      cin >> x;
      vector<pair<int, int> > t;
      for (int j = 0; j < x; ++j) {
        t.push_back(*Sx.begin());
        Sx.erase(Sx.begin());
        Ustaw(Ty, ly, t.back().second + n - 2, -INF);
        Ustaw(Tx, lx, t.back().first, -INF);
      }
      swap(t.back().first, t.back().second);
      Sy.erase(t.back());
      t.pop_back();
      while (t.size() != 0) {
        int lis = Max(Ty, ly, t.back().second + n - 2, n + 8) + 1;
        Sx.insert(t.back());
        Ustaw(Ty, ly, t.back().second + n - 2, lis);
        Ustaw(Tx, lx, t.back().first, lis);
        t.pop_back();
      }
    }
    cout << Max(Tx, lx, 0, n - 1) << endl;
  }
  return 0;
}
