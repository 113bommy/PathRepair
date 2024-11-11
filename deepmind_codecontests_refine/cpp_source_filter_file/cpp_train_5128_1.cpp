#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 5;
const double eps = 1e-7;
const double PI = acos(-1);
void std_quick_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, k;
int res[maxn];
bool check(int x) {
  int cot1, cot2;
  cot1 = cot2 = 0;
  for (int i = 0; i < n; i++) {
    if (res[i] <= x) {
      cot1++;
      i++;
      if (i < n) {
        cot2++;
      }
    }
  }
  if (cot1 >= k / 2 && cot2 >= k - k / 2) return true;
  cot1 = 0;
  cot2 = 1;
  for (int i = 1; i < n; i++) {
    if (res[i] <= x) {
      cot1++;
      i++;
      if (i < n) {
        cot2++;
      }
    }
  }
  if (cot1 >= k / 2 && cot2 >= k - k / 2) return true;
  return false;
}
int main() {
  std_quick_io();
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> res[i];
  }
  int l = 0, r = 1e9 + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
