#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, arr[maxn];
long long cnt(int id) {
  long long res = 0;
  int i = 0;
  while (i < id) {
    res += 2ll * (arr[id] - arr[i]);
    i += m;
  }
  i = n - 1;
  while (i > id) {
    res += 2ll * (arr[i] - arr[id]);
    i -= m;
  }
  return res;
}
long long ter_search() {
  int fi, se, start = 0, end = n;
  for (int i = 0; i < 100; i++) {
    if (end - start <= 4) {
      long long mini = cnt(start);
      for (int j = start + 1; j < end; j++) mini = min(mini, cnt(j));
      return mini;
    }
    fi = start + (end - start) / 3;
    se = start + (2 + end - start) / 3 * 2;
    if (cnt(fi) > cnt(se))
      start = fi;
    else
      end = se;
  }
  if (start + 1 == end) return min(cnt(start), cnt(end));
  return cnt((start + end) / 2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << ter_search() << endl;
  return 0;
}
