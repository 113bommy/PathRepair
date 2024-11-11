#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-20;
const int intINF = 0x3f3f3f3f;
const long long SZ = 200010, SSZ = 1000010, APB = 26, one = 93,
                INF = 0x7fffffffffffffff, mod = 1000000007;
int n, arr[SZ];
set<int> st;
bool ok;
bool judge(int x) {
  if (x & 1) {
    if (x <= n - 1 && arr[x] >= arr[x + 1] || x >= 2 && arr[x] >= arr[x - 1])
      return 0;
  } else {
    if ((x <= n - 1 && arr[x] <= arr[x + 1]) ||
        (x >= 2 && arr[x] <= arr[x - 1]))
      return 0;
  }
  return 1;
}
bool chk(int x, int y) {
  swap(arr[x], arr[y]);
  if (judge(x) == 0) {
    swap(arr[x], arr[y]);
    return 0;
  }
  for (auto it = st.begin(); it != st.end(); ++it) {
    if (judge(*it) == 0) {
      swap(arr[x], arr[y]);
      return 0;
    }
  }
  swap(arr[x], arr[y]);
  return 1;
}
void init() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= n - 1; ++i) {
    if (i & 1) {
      if (arr[i] >= arr[i + 1]) {
        st.insert(i), st.insert(i + 1);
      }
    } else {
      if (arr[i] <= arr[i + 1]) {
        st.insert(i), st.insert(i + 1);
      }
    }
  }
  if (st.size() > 5) {
    cout << 0 << endl;
  } else {
    long long res = 0, x = *st.begin();
    for (int i = 1; i <= n; ++i) {
      if (chk(i, x)) ++res;
      if (chk(i, x + 1)) ++res;
    }
    if (chk(x, x + 1)) --res;
    cout << res << endl;
  }
}
void work() {}
int main() {
  std::ios::sync_with_stdio(0);
  int casenum;
  {
    init();
    work();
  }
  return 0;
}
