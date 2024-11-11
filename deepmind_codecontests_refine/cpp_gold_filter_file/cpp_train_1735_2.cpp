#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
bool cmp(pair<long long, pair<long long, long long>> &p1,
         pair<long long, pair<long long, long long>> &p2) {
  if (p1.first == p2.first) {
    if (p1.second.first == p2.second.first)
      return p1.second.second > p2.second.second;
    else
      return p1.second.first < p2.second.first;
  }
  return p1.first > p2.first;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ;
    vector<pair<long long, pair<long long, long long>>> ans;
    for (int i = 0; i < n; i++) {
      long long num = v[i];
      long long one = 0;
      while (num % 2 == 0) num /= 2, one++;
      long long two = 0;
      while (num % 3 == 0) num /= 3, two++;
      ans.push_back({two, {one, v[i]}});
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < n; i++) cout << ans[i].second.second << " ";
    cout << "\n";
  }
  cerr << "\nTime Taken : " << (float)(clock() - time_p) / CLOCKS_PER_SEC
       << "\n";
}
