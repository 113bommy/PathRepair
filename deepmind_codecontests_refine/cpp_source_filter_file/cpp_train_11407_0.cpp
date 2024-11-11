#include <bits/stdc++.h>
using namespace std;
long long cnt[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e, f, i, j, k, m, n, o, x, y;
  cin >> n >> x;
  long long ar[n];
  for (i = 0; i < n; i++) {
    cin >> ar[i];
    cnt[ar[i]]++;
  }
  long long s = 0;
  for (i = 0; i < n; i++) {
    cnt[ar[i]]--;
    a = ar[i] ^ x;
    if (cnt[a] > 0) s += cnt[a];
  }
  cout << s << "\n";
}
