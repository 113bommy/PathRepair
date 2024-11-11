#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
string s;
long long n, m, k;
long long arr[200001];
long long used[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v;
    long long ind = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      arr[x]++;
      if (arr[x] == 1) {
        v.push_back(x);
      }
      ind = max(ind, arr[x]);
    }
    vector<int> vv;
    for (int i = 0; i < v.size(); i++) {
      vv.push_back(arr[v[i]]);
      arr[v[i]] = 0;
    }
    sort(vv.begin(), vv.end());
    reverse(vv.begin(), vv.end());
    long long ans = 0;
    for (int i = 0; i < vv.size(); i++) {
      if (ind == 0) break;
      if (vv[i] >= ind) {
        ans += ind;
        ind--;
      } else {
        ans += v[i];
        ind = v[i] - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
