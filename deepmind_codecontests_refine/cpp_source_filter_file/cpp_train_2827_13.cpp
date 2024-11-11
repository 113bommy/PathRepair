#include <bits/stdc++.h>
using namespace std;
long long a[200100], cnt[200100], ans, l, r;
void upd(long long sum, long long _l, long long _r) {
  if (sum > ans) {
    ans = sum;
    l = _l, r = _r;
  }
}
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= 200000; ++i) {
    if (cnt[i] != 1 && cnt[i] != 0) {
      continue;
    }
    long long sum = cnt[i], k = 0;
    for (int j = i - 1; j >= 0; --j) {
      if (cnt[j] == 0) {
        upd(sum, j + 1, i);
        break;
      }
      sum += cnt[j];
      if (cnt[j] == 1) k++;
      if (k == 1) {
        upd(sum, j, i);
        break;
      }
    }
  }
  cout << ans << '\n';
  deque<long long> pr;
  for (int i = l; i <= r; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      if (j & 1) {
        pr.push_front(i);
      } else {
        pr.push_back(i);
      }
    }
  }
  for (int i = 0; i < pr.size(); ++i) {
    cout << pr[i] << ' ';
  }
  return 0;
}
