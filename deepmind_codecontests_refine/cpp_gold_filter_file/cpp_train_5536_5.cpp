#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, m, c1 = 0, count2 = 0, m3 = 0;
  cin >> n;
  long long int a[n];
  map<long long int, long long int> m1;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    m1[i] = -1;
  }
  cin >> m;
  vector<long long int> v;
  for (i = 0; i < m; i++) {
    long long int p, q, r;
    cin >> p;
    if (p == 1) {
      cin >> q >> r;
      a[q - 1] = r;
      m1[q - 1] = i;
      v.push_back(0);
    } else {
      cin >> q;
      m3 = max(m3, q);
      v.push_back(q);
    }
  }
  long long int max1[v.size() - 1];
  memset(max1, 0, sizeof(max1));
  long long int m_1 = 0;
  for (i = (m - 1); i >= 0; i--) {
    if (v[i] > m_1) {
      max1[i] = max(m_1, v[i]);
      m_1 = max(m_1, v[i]);
    } else {
      max1[i] = m_1;
      m_1 = max(m_1, v[i]);
    }
  }
  for (i = 0; i < n; i++) {
    if (m1[i] >= m) {
      cout << a[i] << " ";
    } else if (m1[i] != -1) {
      cout << max(a[i], max1[m1[i]]) << " ";
    } else {
      cout << max(a[i], m3) << " ";
    }
  }
  return 0;
}
