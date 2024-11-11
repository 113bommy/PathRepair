#include <bits/stdc++.h>
using namespace std;
void comp() {
  long long i, j, k, n, m;
  long long a;
  cin >> n >> k;
  vector<long long> v1[k + 1];
  map<long long, long long> m1;
  for (i = 0; i < k; i++) {
    cin >> m;
    for (j = 0; j < m; j++) {
      cin >> a;
      m1[a] = i;
      v1[i].push_back(a);
    }
  }
  long long maxi, maxi1;
  cout << "? " << n << " ";
  for (i = 0; i < n; i++) {
    cout << i + 1 << " ";
  }
  cout << endl;
  cin >> maxi;
  long long low = 1, high = n / 2, low1 = high + 1, high1 = n;
  long long ind = -1;
  for (i = 0; i < 10; i++) {
    long long temp = high - low + 1;
    cout << "? " << temp << " ";
    for (j = 0; j < temp; j++) {
      cout << low + j << " ";
    }
    cout << endl;
    cin >> maxi1;
    if (maxi == maxi1) {
      if (low == high) {
        ind = low;
        break;
      }
      high1 = high;
      high = (low + high) / 2;
      low1 = high + 1;
    } else {
      if (low1 == high1) {
        ind = low1;
        break;
      }
      low = low1;
      high = (high1 + low1) / 2;
      low1 = high + 1;
    }
  }
  if (ind == -1) assert(0);
  vector<long long> v2;
  for (i = 0; i < n; i++) {
    if (m1[i + 1] != m1[ind]) {
      v2.push_back(i + 1);
    }
  }
  cout << "? " << v2.size() << " ";
  for (i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }
  cout << endl;
  cin >> maxi1;
  cout << "! ";
  for (i = 0; i < k; i++) {
    if (m1[ind] != i) {
      cout << maxi << " ";
    } else {
      cout << maxi1 << " ";
    }
  }
  cout << endl;
  string s;
  cin >> s;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  long long i = 0, t;
  t = 1;
  cin >> t;
  while (t--) {
    comp();
  }
  return 0;
}
