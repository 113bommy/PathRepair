#include <bits/stdc++.h>
using namespace std;
void hmm() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  hmm();
  long long n;
  cin >> n;
  long long a[1000], b[1000];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  long long cnt = -1;
  if (n == 1) {
    cout << (a[0] + b[0]) << '\n';
    return 0;
  }
  for (int i = 1; i < n; i++) {
    a[i] = a[i] | a[i - 1];
    b[i] = b[i] | b[i - 1];
    cnt = max(cnt, a[i] + b[i]);
  }
  cout << cnt << '\n';
  return 0;
}
