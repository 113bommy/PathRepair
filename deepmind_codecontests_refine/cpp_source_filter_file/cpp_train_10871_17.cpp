#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e3 + 3;
int n, a[Maxn], Max, Min, ans = 1e9;
pair<int, int> q;
void find(int st);
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = (int)(0); i < (int)(n); ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = (int)(0); i < (int)(Maxn * 20 / n); ++i) find(i);
  cout << ans << endl;
  cout << q.first << ' ' << q.second << endl;
  return 0;
}
void find(int st) {
  Min = Max = 0;
  for (int i = (int)(0); i < (int)(n); ++i)
    Max = max(Max, a[i] - st * i - a[0]), Min = min(Min, a[i] - st * i - a[0]);
  int k = (Max + Min) / 2;
  int t = k + a[0];
  int mm = max(abs(k), max(Max - k, k - Min));
  if (mm < ans) {
    ans = mm;
    q = make_pair(t, st);
  }
}
