#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5 + 5;
pair<long long, int> l[maxn], r[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> l[i].first >> r[i].first;
    l[i].second = i;
    r[i].second = i;
  }
  int ptr1 = n - 1, ptr2 = n - 1;
  sort(l, l + n);
  sort(r, r + n);
  long long ans = 0;
  while (ptr1 >= 0) {
    if (l[ptr1].second != r[ptr2].second) {
      ans += max(l[ptr1].first, r[ptr2].first);
      ptr1--;
      ptr2--;
    } else {
      ans = ans + max(l[0].first, r[0].first);
      ptr1--;
      ptr2--;
    }
  }
  cout << ans + n << "\n";
  return 0;
}
