#include <bits/stdc++.h>
using namespace std;
bool s_end(size_t c) { return (c == string ::npos) ? true : false; }
int main() {
  int t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long maxa = *max_element(a, a + n);
    long long mini = *min_element(a, a + n);
    long long cmax = count(a, a + n, maxa);
    long long cmin = count(a, a + n, mini);
    if (maxa == mini)
      cout << 0 << (cmax * (cmax - 1)) / 2;
    else
      cout << maxa - mini << " " << cmax * cmin;
  }
  return 0;
}
