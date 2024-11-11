#include <bits/stdc++.h>
using namespace std;
template <class T>
bool mini(T& a, T b) {
  return a > b ? (a = b, 1) : 0;
}
template <class T>
bool maxi(T& a, T b) {
  return a < b ? (a = b, 1) : 0;
}
const int INF((int)1e9 + 7);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> f = {0, 1};
  while (f[(int)f.size() - 1] < INF)
    f.push_back(f[(int)f.size() - 1] + f[(int)f.size() - 2]);
  for (int i = (0), _b = ((int)f.size()); i < (_b); ++i)
    for (int j = (i), _b = ((int)f.size()); j < (_b); ++j)
      for (int k = (j), _b = ((int)f.size()); k < (_b); ++k) {
        if (f[i] + f[j] + f[k] == n) {
          cout << f[i] << ' ' << f[j] << ' ' << f[k] << '\n';
          return 0;
        }
      }
  cout << "I'm too stupid to solve this problem\n";
  return 0;
}
