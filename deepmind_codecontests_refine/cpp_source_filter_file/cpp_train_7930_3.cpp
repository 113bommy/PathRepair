#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    vector<long long> vec(n);
    vector<long long> first(n, INT_MAX), last(n, INT_MIN);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
      vec[i]--;
      first[vec[i]] = min(first[vec[i]], (long long)i);
      last[vec[i]] = max(last[vec[i]], (long long)i);
    }
    set<long long> myset(vec.begin(), vec.end());
    vec.assign(myset.begin(), myset.end());
    sort(vec.begin(), vec.end());
    long long ans = INT_MIN, temp = 1;
    for (int i = 1; i < vec.size(); i++) {
      if (last[vec[i - 1]] < first[vec[i]]) {
        temp++;
        ans = max(ans, temp);
      } else {
        temp = 1;
      }
    }
    cout << vec.size() - ans << endl;
  }
  return 0;
}
