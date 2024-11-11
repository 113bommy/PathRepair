#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = (int)2e9 + 7;
const long long LINF = (long long)4e18;
template <typename T>
T input() {
  T ans = 0, m = 1;
  char c = ' ';
  while (!((c >= '0' && c <= '9') || c == '-')) c = getchar();
  if (c == '-') m = -1, c = getchar();
  while (c >= '0' && c <= '9') ans = ans * 10 + (c - '0'), c = getchar();
  return ans * m;
}
string nextString(bool flag = false) {
  char ch;
  string ans = "";
  do {
    ch = getchar();
  } while (ch <= ' ');
  while (1) {
    ans += ch;
    ch = getchar();
    if ((!flag && ch <= ' ') || (flag && ch < ' ')) break;
  }
  return ans;
}
char nextChar() {
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  return ch;
}
void read(string& s) { s = nextString(); }
void read(char& c) { c = nextChar(); }
template <typename T>
void read(T& a) {
  a = input<T>();
}
template <typename T, typename... R>
void read(T& a, R&... r) {
  read(a);
  read(r...);
}
int32_t main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  read(n);
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    read(a[i]);
    sum += a[i];
  }
  if (sum != 0) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 1 << " " << n << endl;
    return 0;
  }
  for (int k = 1; k < n; ++k) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < k; ++i) {
      sum1 += a[i];
    }
    for (int i = k; i < n; ++i) {
      sum2 += a[i];
    }
    if (sum1 && sum2) {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << 1 << " " << k << endl;
      cout << k + 1 << " " << n << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
