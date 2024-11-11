#include <bits/stdc++.h>
using namespace std;
const int __n = 1e3 + 5, mod = 1e9 + 7, INF = 0x3f3f3f3f;
template <typename T>
inline void read(T &__result) {
  T x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  __result = x * f;
}
string a, b;
int n;
vector<int> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> a >> b;
    v.clear();
    int len = a.length(), pos[__n];
    for (int i = len - 1, p1 = 0, p2 = len - 1; i >= 0; i--) {
      pos[i] = p1++;
      i--;
      if (i >= 0) pos[i] = p2--;
    }
    int change = 0;
    bool flag = 0;
    for (int i = len - 1; i >= 0; i--) {
      if ((a[pos[i]] == b[i] && change % 2 == 0) ||
          (a[pos[i]] != b[i] && change % 2 == 1)) {
        v.push_back((1));
        v.push_back((i + 1));
        change++;
      } else {
        v.push_back((i + 1));
        change++;
      }
    }
    cout << v.size();
    for (auto i : v) {
      cout << ' ' << i;
    }
    cout << '\n';
  }
}
