#include <bits/stdc++.h>
using namespace std;
int rb = 0, rs = 0, rc = 0;
long long int r, gb, gs, gc, pb, ps, pc;
bool check(long long int x) {
  long long int b = max(0LL, x * rb - gb);
  long long int s = max(0LL, x * rs - gs);
  long long int c = max(0LL, x * rc - gc);
  long long int current_x = b * pb + s * ps + c * pc;
  return current_x <= r;
}
long long int binarySearch(long long int start, long long int end) {
  long long int ans = 0;
  while (start <= end) {
    long long int mid = (start + end) >> 1;
    if (check(mid)) {
      ans = mid;
      start = mid + 1;
    } else
      end = mid - 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      rb++;
    else if (s[i] == 'S')
      rs++;
    else
      rc++;
  }
  cin >> gb >> gs >> gc >> pb >> ps >> pc >> r;
  long long int ans = binarySearch(1, 1e12);
  cout << ans << "\n";
}
