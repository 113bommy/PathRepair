#include <bits/stdc++.h>
using namespace std;
int N, a[500], pos = 0, x, ans;
bool ex;
int main() {
  cin >> N >> x;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    if (a[i] == x) ex = true;
  }
  if (!ex) a[N + 1] = x, ans++, N++;
  sort(a + 1, a + N + 1);
  int mid = (N + 1) / 2;
  for (int i = 1; i <= N; i++) {
    if (a[i] == x) {
      ex = true;
      pos = i;
      if (pos == mid) {
        cout << ans;
        return 0;
      } else if (pos > mid)
        break;
    }
  }
  while (pos != mid) {
    if (mid == pos)
      break;
    else if (mid < pos) {
      N++;
      ans++;
    } else {
      pos++;
      N++;
      ans++;
    }
    mid = (N + 1) / 2;
  }
  cout << ans;
  return 0;
}
