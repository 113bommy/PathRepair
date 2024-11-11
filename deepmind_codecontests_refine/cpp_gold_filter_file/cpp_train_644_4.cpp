#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << ' ' << *it << " = " << a;
  err(++it, args...);
}
const long long MOD = 1e9 + 7;
const int N = 1e6 + 9, M = (1 << 31), OO = 0x3f3f3f3f;
int arr[N];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  set<pair<int, int>> st;
  for (int i = 0; i < x; ++i) st.emplace(arr[i], i);
  while (n--) {
    int y;
    scanf("%d", &y);
    y %= x;
    st.erase({arr[y], y});
    ++arr[y];
    st.insert({arr[y], y});
    printf("%d\n", (st.begin()->first) * x + st.begin()->second);
  }
  return 0;
}
