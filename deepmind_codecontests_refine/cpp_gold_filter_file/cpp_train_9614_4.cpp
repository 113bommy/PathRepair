#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  long long a[51];
  for (long long i = 0; i < n; i++) cin >> a[i];
  pair<long long, int> P[5];
  for (long long i = 0; i < 5; i++) cin >> P[i].first, P[i].second = i;
  stable_sort(P, P + 5, greater<pair<long long, int>>());
  long long cnt[5] = {};
  long long pt = 0;
  for (int i = 0; i < n; i++) {
    pt += a[i];
    for (int j = 0; j < 5; j++) {
      cnt[P[j].second] += pt / P[j].first;
      pt %= P[j].first;
    }
  }
  for (int i = 0; i < 5; i++) cout << cnt[i] << (i == 4 ? "\n" : " ");
  cout << pt << "\n";
}
