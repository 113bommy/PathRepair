#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
long long a[100005];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i] % 3);
  }
  int vis = -1;
  for (int i = 0; i < 3; i++) {
    if (s.count(i) >= k) vis = i;
  }
  if (vis == -1)
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      if (k > 0 && a[i] % 3 == vis) {
        cout << a[i] << " ";
        k--;
      }
    }
    cout << endl;
  }
}
