#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, n, k;
  set<long long int> st;
  vector<long long int> v;
  cin >> n >> k;
  long long int a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (st.count(a[i])) {
      continue;
    } else {
      st.insert(a[i]);
      v.push_back(i);
    }
  }
  if (st.size() >= k) {
    cout << "YES" << endl;
    for (i = 0; i < k; i++) {
      cout << v[i] << " ";
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
