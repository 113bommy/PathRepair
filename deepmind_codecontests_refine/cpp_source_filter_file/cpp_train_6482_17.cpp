#include <bits/stdc++.h>
using namespace std;
long long int i, j, x, y, k;
const int MOD = 1e9 + 7;
long long int m1 = LLONG_MAX;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long int m2 = LLONG_MIN;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  long long int sum = 0;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a;
    for (i = 0; i < n; i++) {
      long long int a1;
      cin >> a1;
      a.push_back(a1);
    }
    long long int count = 0, i = 0;
    while (a[i] == 1) {
      count++;
      i++;
    }
    if (count == n) {
      if (n % 2 == 0)
        cout << "Second" << endl;
      else
        cout << "First" << endl;
    } else {
      if (count % 2 == 0)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    }
  }
}
