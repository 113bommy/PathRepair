#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2, class T3 = hash<T1>>
using umap = unordered_map<T1, T2, T3>;
template <class T>
using uset = unordered_set<T>;
template <class T>
using vec = vector<T>;
const long long infll = numeric_limits<long long>::max() >> 1;
const int inf = numeric_limits<int>::max() >> 1;
const int L = 10;
int n, k, tc;
void input() { cin >> n >> k; }
int ask(int lx, int rx, int ly, int ry) {
  if (ry > n) {
    return 1;
  }
  cout << "? " << rx - lx + 1 << " " << ry - ly + 1 << "\n";
  for (int i = lx; i <= rx; ++i) cout << i << " ";
  cout << "\n";
  for (int i = ly; i <= ry; ++i) cout << i << " ";
  cout << "\n";
  cout.flush();
  string resp;
  cin >> resp;
  if (resp == "FIRST") return 1;
  if (resp == "SECOND") return 2;
  return 0;
}
int first() {
  for (int i = 0; i < 30; ++i) {
    int x = rand() % (n - 1) + 2;
    if (ask(1, 1, x, x) == 2) {
      return 1;
    }
  }
  return 0;
}
int calc(int x) {
  int l = (1 << x) + 1;
  for (int i = x - 1; i >= 0; --i) {
    if (ask(1, (1 << i), l, l + (1 << i) - 1) == 0) {
      l += 1 << i;
    }
  }
  return l;
}
void solve() {
  if (first()) {
    cout << "! 1\n";
    cout.flush();
    return;
  }
  for (int i = 0; i < L; ++i) {
    if (ask(1, (1 << i), 1 + (1 << i), (2 << i)) == 1) {
      int res = calc(i);
      cout << "! " << res << "\n";
      cout.flush();
      return;
    }
  }
}
int main() {
  srand(time(NULL));
  cin >> tc;
  while (tc--) {
    input();
    solve();
  }
}
