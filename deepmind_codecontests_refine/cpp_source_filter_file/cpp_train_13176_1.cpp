#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  cin >> x;
  return x;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &vec) {
  for (int i = 0; i < vec.size(); ++i) in >> vec[i];
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); ++i) out << vec[i] << " ";
  return out;
}
int a[1000001];
int fenwik[1000001];
int n, m;
vector<pair<int, int> > call[1000001];
unordered_map<int, int> lf;
int result[1000001];
inline void xorS(int i, int x) {
  --i;
  for (; i < n; i |= (i + 1)) fenwik[i] ^= x;
}
inline int getXor(int i) {
  --i;
  int x = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) x ^= fenwik[i];
  return x;
}
int main() {
  int a = in(), b = in();
  vector<string> s(a + b);
  for (int i = 0; i < a + b; ++i) cin >> s[i];
  sort((s).begin(), (s).end());
  int g = 0;
  for (int i = 0; i < a + b - 1; ++i) s[i] == s[i + 1] ? ++g : 0;
  int i;
  int check = 0;
  int h = a - g, j = b - g;
  for (i = 0; i < a + b && !check; ++i) {
    if (!(i % 2)) {
      if (g > 0)
        --g;
      else if (h > 0) {
        h--;
      } else
        check = 1;
    } else {
      if (j > 0)
        --j;
      else if (g > 0)
        --g;
      else
        check = 1;
    }
    if (!check) {
      check = 0;
    } else
      break;
  }
  if (i % 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
