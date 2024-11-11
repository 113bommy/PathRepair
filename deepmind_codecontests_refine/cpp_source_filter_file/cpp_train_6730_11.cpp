#include <bits/stdc++.h>
const int N = 200005;
const int MAX_NUM = 100001;
using namespace std;
int a[N], n, r;
bool used[N];
int changed[N];
int cnt[N];
vector<pair<int, int>> odd;
vector<pair<int, int>> even;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  int l = 1e9, r = -1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] += 100000;
    l = min(l, a[i]);
    r = max(r, a[i]);
  }
  if (r - l <= 1) {
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
      cout << a[i] - 100000 << " ";
    }
    return 0;
  }
  int cnt_l = 0, cnt_mid = 0, cnt_r;
  for (int i = 0; i < n; ++i) {
    if (a[i] == l) {
      cnt_l++;
    } else if (a[i] == r) {
      cnt_r++;
    } else {
      cnt_mid++;
    }
  }
  int mid = (l + r) >> 1;
  cnt_l = cnt_r = min(cnt_l, cnt_r);
  if (cnt_mid % 2 == 1) cnt_mid--;
  bool ok = (cnt_l * 2 >= cnt_mid);
  cout << n - max(cnt_l * 2, cnt_mid) << "\n";
  for (int i = 0; i < n; ++i) {
    if (ok) {
      if (a[i] == l && cnt_l) {
        cnt_l--;
        a[i] = mid;
      } else if (a[i] == r && cnt_r) {
        cnt_r--;
        a[i] = mid;
      }
    } else if (a[i] == mid) {
      if (!cnt_mid) continue;
      if (cnt_mid % 2 == 1) {
        a[i] = l;
      } else {
        a[i] = r;
      }
      cnt_mid--;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] - 100000 << ' ';
  }
  return 0;
}
