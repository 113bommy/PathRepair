#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
enum { MOD0 = 1000000000, MOD7 = 1000000007, MOD9 = 1000000009 };
template <typename T>
ostream &operator<<(ostream &cout, vector<T> &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << " ";
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, vector<vector<T> > &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << endl;
  return cout;
}
bool used[601];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    used[a] = 1;
  }
  for (int i = 1; i < sizeof(used) / sizeof(*used); ++i) {
    n += used[i];
  }
  cout << n + 1 << '\n';
  return 0;
}
