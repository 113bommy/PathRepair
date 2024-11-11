#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  std::vector<int> a(n);
  std::vector<int> b(k);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i1 = 0; i1 < k; i1++) cin >> b[i1];
  sort(b.begin(), b.end());
  reverse(b.begin(), b.begin() + k);
  int start = 0;
  for (int i = 0; i < n, start < k; i++) {
    if (a[i] == 0) a[i] = b[start++];
  }
  int cnt1 = 0, cnt2 = 0;
  for (int j = 0; j < n - 1; j++) {
    if (a[j] >= a[j + 1])
      cnt1++;
    else
      cnt2++;
  }
  if (cnt1 > cnt2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
