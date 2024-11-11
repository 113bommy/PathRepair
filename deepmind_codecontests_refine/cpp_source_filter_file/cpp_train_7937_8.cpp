#include <bits/stdc++.h>
using namespace std;
int qwe, qwr;
const long long MOD = 1e9 + 7, MAX = 1e5 + 5;
const int INF = 2e9;
int n, an;
int a[MAX];
bool f, f1, t[MAX], ga, gb;
void clear() {
  for (int i = 0; i < n; i++) t[i] = false;
  f = false;
  f1 = false;
  an = 0;
  ga = false;
  gb = false;
}
void read1(vector<int>& a) {
  cin >> qwe;
  a.push_back(qwe);
}
void read2(vector<pair<int, int>>& a) {
  cin >> qwe >> qwr;
  a.push_back({qwe, qwr});
}
void solve() {
  cin >> n;
  clear();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == (i + 1)) {
      f = true;
    }
    if (a[i] != (i + 1)) {
      f1 = true;
      t[i] = true;
    }
  }
  for (int i = 1; i < n; i++) {
    if (t[i] and !t[i - 1]) {
      ga = true;
      an++;
    } else if (!t[i] and t[i - 1]) {
      an++;
      if (ga) gb = true;
    }
  }
  if (!f1)
    cout << 0;
  else if (!f)
    cout << 1;
  else if (an <= 1)
    cout << 1;
  else if (an == 2 and ga and gb)
    cout << 1;
  else
    cout << 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int __;
  cin >> __;
  while (__--) {
    solve();
    cout << '\n';
  }
  return 0;
}
