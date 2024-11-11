#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int c = 0;
  std::vector<long long int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  if (a[n / 2] < m) {
    for (int i = n / 2; i < n; ++i) {
      if (a[i] < m) c += (m - a[i]);
    }
    cout << c;
  } else if (a[n / 2] > m) {
    for (int i = 0; i < n / 2 + 1; ++i) {
      if (a[i] > m) c += (a[i] - m);
    }
    cout << c;
  } else
    cout << 0;
}
