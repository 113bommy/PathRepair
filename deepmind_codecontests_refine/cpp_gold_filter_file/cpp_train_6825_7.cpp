#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
const int N = 2e5 + 1;
const int B = 1 << 10;
const int K = 3;
int arr[N];
int cpy[N];
int n, s;
int ans;
void counting_sort(int r, int b) {
  int cnt[B] = {0};
  for (int i = 1; i <= n; ++i) {
    cnt[(arr[i] >> r) & b]++;
  }
  for (int i = 1; i < B; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    cnt[(arr[i] >> r) & b]--;
    cpy[cnt[(arr[i] >> r) & b]] = arr[i];
  }
  copy(cpy, cpy + n, arr + 1);
}
void radix_sort() {
  for (int i = 0; i < K; ++i) {
    counting_sort(i * 10, B - 1);
  }
}
void input() {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    if (!arr[i] && i != s) {
      arr[i] = inf;
    } else if (i == s) {
      ans = !!arr[i];
      arr[i] = 0;
    }
  }
  radix_sort();
}
void solve() {
  int lst = 0;
  for (int i = 1; i <= n;) {
    if (lst + 1 < arr[i]) {
      arr[n--] = ++lst;
      ans++;
    } else {
      lst = arr[i++];
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  solve();
}
