#include <bits/stdc++.h>
using namespace std;
inline void _() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
void __() {}
inline void ___(char *i, char *j) {
  freopen(i, "r", stdin);
  freopen(j, "w", stdout);
}
template <class T1>
bool tk(T1 &e1) {
  if (cin >> e1) return true;
  return false;
}
template <class T1, class T2>
bool tk(T1 &e1, T2 &e2) {
  if (cin >> e1 >> e2) return true;
  return false;
}
template <class T1, class T2, class T3>
bool tk(T1 &e1, T2 &e2, T3 &e3) {
  if (cin >> e1 >> e2 >> e3) return true;
  return false;
}
template <class T1, class T2, class T3, class T4>
bool tk(T1 &e1, T2 &e2, T3 &e3, T4 &e4) {
  if (cin >> e1 >> e2 >> e3 >> e4) return true;
  return false;
}
template <class T1, class T2, class T3, class T4, class T5>
bool tk(T1 &e1, T2 &e2, T3 &e3, T4 &e4, T5 &e5) {
  if (cin >> e1 >> e2 >> e3 >> e4 >> e5) return true;
  return false;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
bool tk(T1 &e1, T2 &e2, T3 &e3, T4 &e4, T5 &e5, T6 &e6) {
  if (cin >> e1 >> e2 >> e3 >> e4 >> e5 >> e6) return true;
  return false;
}
template <class T1>
void put(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void put(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void put(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void put(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void put(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void put(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
template <class T1>
void putVec(vector<T1> e1) {
  for (int i = 0; i < (e1).size(); i++)
    (!i ? cout << e1[i] : cout << " " << e1[i]);
  cout << endl;
}
template <class T1>
void putArr(T1 arr[], int l) {
  for (int i = 0; i < l; i++) (!i ? cout << arr[i] : cout << " " << arr[i]);
  cout << endl;
}
template <class T1>
void bug(T1 e) {}
template <class T1, class T2>
void bug(T1 e1, T2 e2) {}
template <class T1, class T2, class T3>
void bug(T1 e1, T2 e2, T3 e3) {}
template <class T1, class T2, class T3, class T4>
void bug(T1 e1, T2 e2, T3 e3, T4 e4) {}
template <class T1, class T2, class T3, class T4, class T5>
void bug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void bug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {}
template <class T1>
void bugVec(vector<T1> e1) {}
template <class T1>
void bugArr(T1 arr[], int l) {}
template <typename T>
inline bool isOn(T &mask, int pos) {
  return ((mask) & (1 << pos));
}
template <typename T>
inline void setOff(T &mask, int pos) {
  mask = ((mask) & (~(1 << pos)));
}
template <typename T>
inline void setOn(T &mask, int pos) {
  mask = ((mask)(1 << pos));
}
namespace gv {};
long long absolute(long long a) {
  if (a < 0) return -a;
  return a;
}
int main() {
  _();
  vector<pair<int, pair<int, int> > > ans(2);
  ans[0] = {
      2 * (long long int)1000000000,
      {2 * (long long int)1000000000 + 1, 2 * (long long int)1000000000 + 1}};
  int n, m, c;
  vector<int> a, b;
  tk(n);
  for (int i = 0; i < n; i++) tk(c), a.push_back(c);
  sort(a.begin(), a.end());
  tk(m);
  for (int i = 0; i < m; i++) tk(c), b.push_back(c);
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    for (int j = -1; j < 1; j++) {
      int lo = max(a[i] + j, 0);
      int binaryLo = 0, binaryHi = a.size();
      while (binaryLo < binaryHi) {
        int mid = binaryLo + (binaryHi - binaryLo) / 2;
        if (a[mid] <= lo)
          binaryLo = mid + 1;
        else
          binaryHi = mid;
      }
      long long A = binaryLo * 2 + ((int)a.size() - binaryLo) * 3;
      binaryLo = 0, binaryHi = b.size();
      while (binaryLo < binaryHi) {
        int mid = binaryLo + (binaryHi - binaryLo) / 2;
        if (b[mid] <= lo)
          binaryLo = mid + 1;
        else
          binaryHi = mid;
      }
      long long B = binaryLo * 2 + ((int)b.size() - binaryLo) * 3;
      bug(A, B, lo, binaryLo);
      ans[1] = {-1 * A + B, {-1 * A, B}};
      sort(ans.begin(), ans.end());
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = -1; j < 1; j++) {
      int lo = max(b[i] + j, 0);
      int binaryLo = 0, binaryHi = a.size();
      while (binaryLo < binaryHi) {
        int mid = binaryLo + (binaryHi - binaryLo) / 2;
        if (a[mid] <= lo)
          binaryLo = mid + 1;
        else
          binaryHi = mid;
      }
      long long A = binaryLo * 2 + ((int)a.size() - binaryLo) * 3;
      binaryLo = 0, binaryHi = b.size();
      while (binaryLo < binaryHi) {
        int mid = binaryLo + (binaryHi - binaryLo) / 2;
        if (b[mid] <= lo)
          binaryLo = mid + 1;
        else
          binaryHi = mid;
      }
      long long B = binaryLo * 2 + ((int)b.size() - binaryLo) * 3;
      bug(A, B, lo, binaryLo);
      ans[1] = {-1 * A + B, {-1 * A, B}};
      sort(ans.begin(), ans.end());
    }
  }
  cout << (-1 * (ans[0].second.first)) << ":" << ans[0].second.second << endl;
  __();
}
