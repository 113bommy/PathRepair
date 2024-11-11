#include <bits/stdc++.h>
using namespace std;
long long a[100005];
stack<long long> s;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n / 2; i++) {
      s.push(a[n - 1 - i]);
      s.push(a[i]);
    }
    if (n % 2 == 1) s.push(a[n / 2]);
    while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << "\n";
  }
  return 0;
}
