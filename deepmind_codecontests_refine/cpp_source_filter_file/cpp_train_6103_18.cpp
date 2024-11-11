#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n;
int x[maxn], y[maxn];
int ask(int pi, int bi) {
  cout << "? " << pi << " " << bi << endl;
  int res;
  cin >> res;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    x[i] = ask(i, 0);
  }
  for (int i = 0; i < n; i++) {
    y[i] = ask(0, i);
  }
  int count = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    vector<int> p(n);
    for (int j = 0; j < n; j++) {
      p[j] = x[j] ^ i;
      if (p[j] < 0 || p[j] >= n) {
        ok = false;
        break;
      }
    }
    if (!ok || p[i] != 0) {
      continue;
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++) {
      b[p[j]] = i;
    }
    for (int j = 0; j < n; j++) {
      if (y[j] != (p[0] ^ b[j])) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = p;
      count++;
    }
  }
  cout << "!" << endl;
  cout << count << endl;
  for (int x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
