#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, arr[N], cnt[2];
bool mark[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] != 0) mark[arr[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      cnt[i % 2]++;
    }
  }
  int start = 1;
  while (arr[start] == 0) {
    start++;
    if (start > n) {
      start = -1;
      break;
    }
  }
  int en = n;
  while (arr[en] == 0) {
    en--;
    if (en == 0) {
      en = -1;
      break;
    }
  }
  if (start == -1 || en == -1) {
    if (n == 1) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
    }
    return 0;
  }
  vector<pair<int, int>> vc, vc2;
  if (start != 1) {
    vc2.push_back({start - 1, arr[start] % 2});
  }
  if (en != n) {
    vc2.push_back({n - en, arr[en] % 2});
  }
  int cur = 0;
  int fm = -1;
  int ans = 0;
  for (int i = start + 1; i <= n; i++) {
    if (arr[i] == 0 && arr[i - 1] != 0) {
      cur = 1;
      fm = arr[i - 1] % 2;
    } else {
      if (arr[i] == 0) {
        cur++;
      } else {
        if (arr[i] % 2 == fm) {
          vc.push_back({cur, fm});
          cur = 0;
          fm = -1;
        } else if (arr[i - 1] == 0) {
          ans++;
          fm = -1;
          cur = 0;
        } else {
          fm = -1;
          cur = 0;
        }
      }
    }
  }
  sort(vc.begin(), vc.end());
  for (int i = 2; i <= n; i++) {
    if (arr[i] != 0 && arr[i - 1] != 0 && arr[i] != arr[i - 1]) {
      ans++;
    }
  }
  for (auto x : vc) {
    if (cnt[x.second] >= x.first) {
      cnt[x.second] -= x.first;
    } else {
      ans += 2;
    }
  }
  for (auto x : vc2) {
    if (cnt[x.second] >= x.first) {
      cnt[x.second] -= x.first;
    } else {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
