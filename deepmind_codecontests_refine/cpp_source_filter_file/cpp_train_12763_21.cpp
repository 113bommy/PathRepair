#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
const int inf = 0x3f3f3f3f;
long long a[maxn];
int q[maxn];
int main() {
  int n;
  cin >> n;
  long long p = 0;
  int pans = 0;
  for (int i = (1); i < (n + 1); i++) {
    cin >> a[i];
    pans += abs(a[i] - i);
    if (i < a[i]) {
      p++;
      q[a[i] - i]--;
    }
  }
  long long ans1 = pans, ans2 = 0;
  int cur = n;
  for (int i = (1); i < (n + 1); i++) {
    pans -= p;
    pans += n - p - 1;
    pans = pans - abs(a[cur] - n) + abs(a[cur] - 1);
    if (ans1 > pans) ans1 = pans, ans2 = i;
    p += q[i];
    if (1 < a[cur]) {
      p++;
      q[a[cur] - 1 + i]--;
    }
    cur--;
  }
  cout << ans1 << ' ' << ans2 << endl;
  return 0;
}
