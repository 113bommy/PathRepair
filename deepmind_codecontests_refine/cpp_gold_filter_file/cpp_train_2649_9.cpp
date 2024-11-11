#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long totalTime = 0;
  if (n >= m) {
    for (int i = 0; i < m; i++) totalTime = totalTime + a[i] * (m - i);
    for (int i = m; i < n; i++) totalTime = totalTime + a[i];
  } else {
    for (int i = 0; i < n; i++) totalTime = totalTime + a[i] * (m - i);
  }
  cout << totalTime << endl;
}
