#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
template <typename INint>
inline void IN(INint &first) {
  first = 0;
  int f = 1;
  char c;
  cin.get(c);
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    cin.get(c);
  }
  while (c >= '0' && c <= '9') {
    first = first * 10 + c - '0';
    cin.get(c);
  }
  first *= f;
}
template <typename INint>
inline void OUT(INint first) {
  if (first > 9) OUT(first / 10);
  cout.put(first % 10 + '0');
}
const int maxn = int(-1);
int a[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
int main() {
  int T(1), times(0);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (++times, T--) {
    set<int> S;
    for (int i = 0; i < int(18); i++) S.insert(a[i]);
    int n;
    cin >> n;
    if (S.count(n))
      cout << "red" << endl;
    else
      cout << "black" << endl;
  }
  return 0;
}
