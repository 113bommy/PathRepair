#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T S(T a) {
  return a * a;
}
template <typename T>
inline string tostring(T a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <typename T>
inline long long tolong(T a) {
  long long res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <typename T>
inline unsigned long long bigmod(T a, T b, T m) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return S(bigmod(a, b / 2, m)) % m;
  else
    return (a % m * bigmod(a, b - 1, m)) % m;
}
template <typename T>
inline vector<string> parse(T str) {
  vector<string> res;
  string s;
  istringstream os(str);
  while (os >> s) res.push_back(s);
  return res;
}
template <typename T>
inline unsigned long long dist(T A, T B) {
  unsigned long long res =
      (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
  return res;
}
int arr[10000010];
vector<int> a, b;
int main() {
  int n, m;
  int i, j, k;
  int ks = 2;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> m;
    ks++;
    arr[m] = ks;
    for (j = b.size() - 1; j >= 0; j--) {
      k = (m | b[j]);
      if (arr[k] == ks)
        continue;
      else {
        arr[k] = ks;
        a.push_back(k);
      }
    }
    a.push_back(m);
    b = a;
    a.clear();
  }
  int res = 0;
  for (int i = (1); i < (10000001); i++)
    if (arr[i]) res++;
  cout << res << endl;
}
