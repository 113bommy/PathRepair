#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> freq(100005, 0);
  vector<int> cnt(100005, 0);
  set<int> u;
  for (int i = 0; i < n; i++) {
    u.insert(a[i]);
  }
  int l = u.size();
  cnt[0] = 0;
  int ans = 0;
  u.clear();
  for (int i = 0; i < n; i++) {
    u.insert(a[i]);
    cnt[freq[a[i]]]--;
    freq[a[i]]++;
    cnt[freq[a[i]]]++;
    int pc = cnt[freq[a[i]] - 1];
    int cc = cnt[freq[a[i]]];
    int tc = cnt[freq[a[i]] + 1];
    int l = u.size();
    if (l == 1 || cnt[1] == l ||
        (cnt[1] == 1 && i % (l - 1) == 0 && cnt[i / (l - 1)] == (l - 1))) {
      ans = i + 1;
    } else if ((pc == (l - 1) && cc == 1) || (cc == (l - 1) && tc == 1)) {
      ans = i + 1;
    }
  }
  cout << ans << endl;
}
