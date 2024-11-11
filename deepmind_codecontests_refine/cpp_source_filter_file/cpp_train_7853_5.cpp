#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int>& v) {
  if (v.size() == 1) {
    return;
  } else {
    int len = v.size();
    vector<int> temp_l(v.begin(), v.begin() + (len >> 1));
    merge_sort(temp_l);
    vector<int> temp_r(v.begin() + (len >> 1), v.end());
    merge_sort(temp_r);
    merge(temp_l.begin(), temp_l.end(), temp_r.begin(), temp_r.end(),
          v.begin());
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& i : v) {
    cin >> i;
  }
  merge_sort(v);
  cout << v.back() - v[0] << " ";
  long long ans = 1;
  if (v[0] != v.back()) {
    ans *= 1ll * count(v.begin(), v.end(), v[0]) *
           count(v.begin(), v.end(), v.back());
  } else {
    ans *= 1ll *
           (count(v.begin(), v.end(), v[0]) *
            (count(v.begin(), v.end(), v[0]) - 1)) /
           2;
  }
  cout << ans << '\n';
  return 0;
}
