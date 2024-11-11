#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int iMAX = INT_MAX;
const int iMIN = -INT_MAX;
int main(void) {
  int n, k;
  cin >> n >> k;
  int jobs[100000] = {0};
  int a[100000], b[100000];
  int ujobs = 0;
  vector<pair<int, int> > v;
  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    if (jobs[a[i]] == 0) ujobs++;
    jobs[a[i]]++;
  }
  for (int i = 0; i <= n - 1; i++) {
    cin >> b[i];
    if (jobs[a[i]] > 1) v.push_back({b[i], a[i]});
  }
  long long time = 0;
  sort(v.begin(), v.end());
  for (auto x : v) {
    if (ujobs >= k) break;
    if (jobs[x.second] > 1) {
      time += x.first;
      ujobs++;
      jobs[x.second] -= 1;
    }
  }
  cout << time;
  return 0;
}
