#include <bits/stdc++.h>
using namespace std;
struct Mo {
  long long l, r, id;
} Q[1000500];
long long n, q, block, arr[1000500], cnt[1000500], ans[1000500], current_ans;
bool cmp(const Mo& x, const Mo& y) {
  if (x.l / block != y.l / block) return x.l < y.l;
  return x.r < y.r;
}
void add(long long x) {
  current_ans -= cnt[x] * cnt[x] * x;
  cnt[x]++;
  current_ans += cnt[x] * cnt[x] * x;
}
void _remove(long long x) {
  current_ans -= cnt[x] * cnt[x] * x;
  cnt[x]--;
  current_ans += cnt[x] * cnt[x] * x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  block = sqrt(n);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 0; i < q; i++) {
    cin >> Q[i].l >> Q[i].r;
    Q[i].id = i;
  }
  sort(Q, Q + q, cmp);
  int mo_left = 0, mo_right = -1;
  for (int i = 0; i < q; i++) {
    int left = Q[i].l;
    int right = Q[i].r;
    while (mo_right < right) {
      mo_right++;
      add(arr[mo_right]);
    }
    while (mo_right > right) {
      _remove(arr[mo_right]);
      mo_right--;
    }
    while (mo_left < left) {
      _remove(arr[mo_left]);
      mo_left++;
    }
    while (mo_left > left) {
      mo_left--;
      add(arr[mo_left]);
    }
    ans[Q[i].id] = current_ans;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
