#include <bits/stdc++.h>
using namespace std;
void sprint(int x) { cout << x; }
void sprint(long x) { cout << x; }
void sprint(long long x) { cout << x; }
void sprint(unsigned x) { cout << x; }
void sprint(unsigned long x) { cout << x; }
void sprint(unsigned long long x) { cout << x; }
void sprint(float x) { cout << x; }
void sprint(double x) { cout << x; }
void sprint(long double x) { cout << x; }
void sprint(char x) { cout << '\'' << x << '\''; }
void sprint(const char *x) { cout << '\"' << x << '\"'; }
void sprint(const string &x) { cout << '\"' << x << '\"'; }
void sprint(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void sprint(const pair<T, V> &x);
template <typename T>
void sprint(const vector<T> &x);
template <typename T, typename V>
void sprint(const pair<T, V> &x) {
  cout << '{';
  sprint(x.first);
  cout << ',';
  sprint(x.second);
  cout << "}";
}
template <typename T>
void sprint(const vector<T> &x) {
  cout << "{";
  for (int u69 = 0; u69 < x.size(); u69++) {
    sprint(x[u69]);
    cout << (u69 + 1 == x.size() ? "" : ",");
  };
  cout << "}";
}
template <typename T>
void sprint(const T &x) {
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), sprint(i);
  cout << "}";
}
void sprint() { cout << "]\n"; }
template <typename T, typename... V>
void sprint(T t, V... v) {
  sprint(t);
  if (sizeof...(v)) cout << ", ";
  sprint(v...);
}
inline long long ceil2(long long a, long long b) { return (a + b - 1) / b; }
inline bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
bool isPerfectSquare(long long x) {
  long long sr = sqrt(x);
  return ((sr * sr) == x);
}
bool isIn(string &s2, string &s1) {
  if (s1.find(s2) != string::npos) return true;
  return false;
}
bool isSorted(vector<int> &a) {
  for (int i = 0; i < (int)a.size() - 1; i++)
    if (a[i] > a[i + 1]) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int count = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == 'W' && ((a[i + 1][j] == 'P' && i + 1 < n) ||
                             (a[i - 1][j] == 'P' && i - 1 >= 0) ||
                             (a[i][j + 1] == 'P' && j + 1 < m) ||
                             (a[i][j - 1] == 'P' && j - 1 >= 0))) {
        count++;
      }
    }
  }
  cout << count << "\n";
  return 0;
}
