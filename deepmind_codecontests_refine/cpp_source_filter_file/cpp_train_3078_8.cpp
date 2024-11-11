#include <bits/stdc++.h>
using namespace std;
const int Max = 1e3 + 10;
int n, x, y;
int A[Max];
int B[Max];
set<pair<int, int>, greater<pair<int, int>>> _01, _02, _10, _12, _20, _21;
set<int> ansA, ansB;
int res;
void upd(int i, int cur, int nxt) {
  int a = A[i], b = B[i];
  if (cur == 0) {
    _01.erase(make_pair(a, i));
    _02.erase(make_pair(b, i));
  } else if (cur == 1) {
    res -= a;
    ansA.erase(i);
    _10.erase(make_pair(-a, i));
    _12.erase(make_pair(b - a, i));
  } else {
    res -= b;
    ansB.erase(i);
    _20.erase(make_pair(-b, i));
    _21.erase(make_pair(a - b, i));
  }
  if (nxt == 0) {
    _01.insert(make_pair(a, i));
    _02.insert(make_pair(b, i));
  } else if (nxt == 1) {
    res += a;
    ansA.insert(i);
    _10.insert(make_pair(-a, i));
    _12.insert(make_pair(b - a, i));
  } else {
    res += b;
    ansB.insert(i);
    _20.insert(make_pair(-b, i));
    _21.insert(make_pair(a - b, i));
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];
  for (int i = 0; i < x; i++) {
    res += A[i];
    ansA.insert(i);
    _10.insert(make_pair(-A[i], i));
    _12.insert(make_pair(B[i] - A[i], i));
  }
  for (int i = x; i < x + y; i++) {
    res += B[i];
    ansB.insert(i);
    _20.insert(make_pair(-B[i], i));
    _21.insert(make_pair(A[i] - B[i], i));
  }
  for (int i = x + y; i < n; i++) {
    _01.insert(make_pair(A[i], i));
    _02.insert(make_pair(B[i], i));
  }
  while (true) {
    bool change = false;
    if (x >= 1 && y >= 1 && x + y < n) {
      pair<int, int> a = *_12.begin();
      pair<int, int> b = *_20.begin();
      pair<int, int> c = *_01.begin();
      if (a.first + b.first + c.first >= 1) {
        change = true;
        upd(a.second, 1, 2);
        upd(b.second, 2, 0);
        upd(c.second, 0, 1);
      }
    }
    if (x >= 1 && y >= 1 && x + y < n) {
      pair<int, int> a = *_21.begin();
      pair<int, int> b = *_10.begin();
      pair<int, int> c = *_02.begin();
      if (a.first + b.first + c.first >= 1) {
        change = true;
        upd(a.second, 2, 1);
        upd(b.second, 1, 0);
        upd(c.second, 0, 2);
      }
    }
    if (x >= 1 && x + y < n) {
      pair<int, int> a = *_01.begin();
      pair<int, int> b = *_10.begin();
      if (a.first + b.first > 0) {
        change = true;
        upd(a.second, 0, 1);
        upd(b.second, 1, 0);
      }
    }
    if (y >= 1 && x + y < n) {
      pair<int, int> a = *_02.begin();
      pair<int, int> b = *_20.begin();
      if (a.first + b.first > 0) {
        change = true;
        upd(a.second, 0, 2);
        upd(b.second, 2, 0);
      }
    }
    if (x >= 1 && y >= 1) {
      pair<int, int> a = *_12.begin();
      pair<int, int> b = *_21.begin();
      if (a.first + b.first > 0) {
        change = true;
        upd(a.second, 1, 2);
        upd(b.second, 2, 1);
      }
    }
    if (!change) break;
  }
  cout << res << '\n';
  for (int i : ansA) cout << i + 1 << " ";
  cout << '\n';
  for (int i : ansB) cout << i + 1 << " ";
  cout << '\n';
}
