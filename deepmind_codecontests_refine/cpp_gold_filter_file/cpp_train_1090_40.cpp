#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
const double PI = 2 * acos(0.0);
const long double eps = 1e-12;
const int infi = 1e9;
const long long Linfi = (long long)9e18;
const long long MOD = 1000000007;
int n;
long long E;
vector<int> V;
long long ans = 0;
void duyet(int hang, long long pos) {
  if (hang == n + 1) return;
  long long cha = pos / 2;
  int ok = 0;
  if (cha * 2 == pos)
    ok = 1;
  else
    ok = 0;
  if (ok == 1 || hang == 1) {
    if (V[hang] == 1) {
      ans += (1LL << (n - hang + 1)) - 1;
    }
    ans++;
  } else if (ok == 0) {
    if (V[hang] == 0) {
      ans += (1LL << (n - hang + 1)) - 1;
    }
    ans++;
  }
  if (V[hang] == 0)
    duyet(hang + 1, 2 * pos - 1);
  else
    duyet(hang + 1, 2 * pos);
}
void solve() {
  long long cur = E;
  for (int step = 1; step <= n; step++) {
    long long tmp = cur / 2;
    if (tmp * 2 == cur) {
      V.push_back(1);
      cur = tmp;
    } else {
      V.push_back(0);
      cur = (cur + 1) / 2;
    }
  }
  V.push_back(-1);
  reverse(V.begin(), V.end());
  duyet(1, 1);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> E;
  solve();
  return 0;
}
