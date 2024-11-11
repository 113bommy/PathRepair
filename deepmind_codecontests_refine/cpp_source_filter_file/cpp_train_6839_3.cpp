#include <bits/stdc++.h>
using namespace std;
long long int a[1000];
set<long long int> s;
vector<long long int> v;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long int n, k;
  cin >> n >> k;
  for (long long int i = 0; i < n; i = i + 1) {
    cin >> a[i];
    s.insert(a[i]);
  }
  if (s.size() < k) {
    cout << "NO";
    return 0;
  }
  cout << "YES"
       << "\n";
  long long int q = 0;
  for (long long int i = 0; i < n; i = i + 1) {
    long long int m = 0;
    for (long long int j = 0; j < v.size(); j = j + 1) {
      if (a[i] == v[j]) {
        m = 1;
        break;
      }
    }
    if (m == 0 && q <= k) {
      q++;
      cout << i + 1 << " ";
      v.push_back(a[i]);
    }
  }
}
