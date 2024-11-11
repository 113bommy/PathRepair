#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int i, j, k, l, r, n, m, it;
  cin >> n >> k >> l;
  if (k > l) swap(k, l);
  if (k == 1) {
    for (i = 1; i <= n; i++) cout << i << " ";
    return 0;
  }
  if (n % k == 0) {
    j = n / k;
    vector<long long int> v;
    for (i = 0; i < j; i++) {
      if (i == 0) {
        for (it = 1; it < k; it++) {
          v.push_back(it + 1);
        }
        v.push_back(1);
      } else {
        r = v[v.size() - 2];
        r++;
        for (it = r; it < r + k - 1; it++) v.push_back(it + 1);
        v.push_back(r);
      }
    }
    for (i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
  } else if (n % l == 0) {
    j = n / l;
    vector<long long int> v;
    for (i = 0; i < j; i++) {
      if (i == 0) {
        for (it = 1; it < l; it++) {
          v.push_back(it + 1);
        }
        v.push_back(1);
      } else {
        r = v[v.size() - 2];
        r++;
        for (it = r; it < r + l - 1; it++) v.push_back(it + 1);
        v.push_back(r);
      }
    }
    for (i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
  }
  long long int q;
  for (q = 0; q <= n / l; q++) {
    if ((n - q * l) % k == 0) break;
  }
  if (q <= n / l) {
    j = n % l;
    j = n / l;
    vector<long long int> v;
    for (i = 0; i < q; i++) {
      if (i == 0) {
        for (it = 1; it < l; it++) {
          v.push_back(it + 1);
        }
        v.push_back(1);
      } else {
        r = v[v.size() - 2];
        r++;
        for (it = r; it < r + l - 1; it++) v.push_back(it + 1);
        v.push_back(r);
      }
    }
    long long int p = (n - l * q);
    j = p / k;
    for (i = 0; i < j; i++) {
      r = v[v.size() - 2];
      r++;
      for (it = r; it < r + k - 1; it++) v.push_back(it + 1);
      v.push_back(r);
    }
    for (i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
  } else
    cout << "-1" << endl;
}
