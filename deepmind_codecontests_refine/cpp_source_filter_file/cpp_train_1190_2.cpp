#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010, MAXV = 20202;
const int OFFSET = 10001;
int N;
int a[MAXN];
int sq[MAXV];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < MAXV; i++) sq[i] = ((i - OFFSET) * (i - OFFSET));
  int ans = INF;
  for (int i = 0; i < N; i++) {
    int s = 0, c = 0;
    for (int j = i; j < N && s < ans; j++) {
      s += (j - i) * 2 + 1;
      c += a[j];
      if (c + OFFSET > 0 && c + OFFSET < MAXV)
        ans = min(ans, s + sq[c + OFFSET]);
    }
  }
  cout << ans << '\n';
  return 0;
}
