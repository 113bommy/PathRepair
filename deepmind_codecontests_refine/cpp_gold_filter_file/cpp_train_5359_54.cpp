#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const int maxn = 110;
bool boy[maxn];
bool girl[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int b, g;
  cin >> b;
  for (int i = 0; i < b; i++) {
    int a;
    cin >> a;
    boy[a] = true;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int a;
    cin >> a;
    girl[a] = true;
  }
  for (int i = 0; i < n * m * n * m; i++) {
    int i1 = i % n;
    int i2 = i % m;
    if (boy[i1] || girl[i2]) {
      boy[i1] = true;
      girl[i2] = true;
    }
  }
  bool result = true;
  for (int i = 0; i < n; i++) result &= boy[i];
  for (int i = 0; i < m; i++) result &= girl[i];
  if (result)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}
