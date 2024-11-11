#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n, k;
int book[100005];
vector<int> ans;
bool erfen(long long mid) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += min(a[i], mid);
  }
  if (sum >= k) return true;
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> k;
  long long sum = 0;
  long long Max = 0;
  long long L, R, mid;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    Max = max(Max, a[i]);
  }
  if (sum < k)
    cout << -1 << endl;
  else if (sum == k) {
  } else {
    L = 0, R = Max, mid;
    while (L <= R) {
      mid = L + R >> 1;
      if (erfen(mid)) {
        R = mid - 1;
      } else {
        L = mid + 1;
      }
    }
    long long kk = R;
    sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += min(a[i], kk);
      a[i] -= min(a[i], kk);
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      if (sum > k && a[i] > 0) {
        book[i] = 1;
        ans.push_back(i);
      } else if (a[i] > 0) {
        sum++;
        a[i]--;
        if (sum > k && flag && a[i] == 0) {
          flag = 0;
          ans.push_back(i);
          book[i] = 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!book[i] && a[i] > 0) {
        book[i] = 1;
        ans.push_back(i);
      }
    }
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
  }
}
