#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long int a[n];
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  vector<int> ans;
  long long int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += v[n - i - 1].first;
    ans.push_back(v[n - i - 1].second);
  }
  sort(ans.begin(), ans.end());
  cout << sum << endl;
  int pr = 0;
  for (int i = 0; i < k - 1; i++) {
    cout << ans[i + 1] - pr << " ";
    pr = ans[i] + 1;
  }
  cout << n - 1 - pr << endl;
}
