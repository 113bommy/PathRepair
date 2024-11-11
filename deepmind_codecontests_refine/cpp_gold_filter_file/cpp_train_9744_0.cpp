#include <bits/stdc++.h>
using namespace std;
void Arr2DInit(vector<vector<int> > &a, int n, int m) {
  a.resize(n);
  for (int i = 0; i < n; i++) a[i].resize(m);
}
template <class T>
T minn(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T maxx(T a, T b) {
  return a > b ? a : b;
}
long long Pow(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  if (n % 2 == 0)
    return Pow(a, n / 2) * Pow(a, n / 2);
  else
    return Pow(a, n / 2) * Pow(a, n / 2) * a;
}
bool Cmp(pair<int, int> a, pair<int, int> b) { return a > b; }
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
string direct = "UDRL";
pair<int, int> a[300007];
int main() {
  int n, k, add = 0, x;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    add += 2 * (k - x) - 1;
  }
  cout << maxx(add, 0);
}
