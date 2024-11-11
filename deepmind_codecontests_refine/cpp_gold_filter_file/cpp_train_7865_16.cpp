#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
int n, x;
vector<int> a;
bool prime(int g) {
  if (g == 1) return false;
  for (int x = 2; x * x <= g; x++) {
    if (g % x == 0) return false;
  }
  return true;
}
int ans = 0;
bool good(int rg, vector<int>& a) {
  int it = 0;
  for (int g = 2; g <= rg; g++) {
    if (prime(g)) {
      while (it < int((a).size()) && a[it] < g) it++;
      if (it == int((a).size()) || a[it] != g) return false;
      ans++;
    }
  }
  return true;
}
int solve() {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  if (x == 2) return 0;
  if (int((a).size()) == 0) return -1;
  if (a[0] == 1) return 1;
  if (good(x - 1, a)) return ans;
  return -1;
}
int main() {
  cin >> n >> x;
  a.resize(n);
  for (int i = 0; i < int(n); ++i) scanf("%d", &a[i]);
  cout << solve() << endl;
  return 0;
}
