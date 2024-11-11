#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, d, t = 0;
  cin >> n >> d;
  vector<int> a(n);
  int count[101] = {0};
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
    count[a[i]]++;
  }
  sort(a.begin(), a.end());
  long long int res = INT_MAX;
  for (int i = 0; i < a.size(); i++) {
    t = i;
    for (int j = i; j < a.size(); j++) {
      if (abs(a[i] - a[j]) > d) {
        t++;
      }
    }
    res = min(res, t);
  }
  cout << res;
}
