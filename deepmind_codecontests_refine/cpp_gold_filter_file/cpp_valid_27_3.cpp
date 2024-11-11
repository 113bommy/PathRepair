#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const long double eps = 1e-9;
const int inf = 1.01e9;
const long long MOD = 1e9 + 7;
const string Y = "YES";
const string N = "NO";
template <typename T>
int sz(T structure) {
  return (int)(structure.size());
}
template <typename T>
void print(T structure) {
  for (auto el : structure) {
    cout << el << " ";
  }
  cout << endl;
}
template <typename T>
void read(T& structure, int size) {
  for (int i = 0; i < size; ++i) {
    cin >> structure[i];
  }
}
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = sz(s1);
  int m = sz(s2);
  int ptrS1 = n - 1;
  int ptrS2 = m - 1;
  while (ptrS1 >= 0 && ptrS2 >= 0) {
    if (s1[ptrS1] == s2[ptrS2]) {
      ptrS1--;
      ptrS2--;
    } else {
      ptrS1 -= 2;
    }
  }
  if (ptrS2 == -1)
    cout << Y << endl;
  else
    cout << N << endl;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  cout << endl;
  return 0;
}
