#include <bits/stdc++.h>
using namespace std;
bool compFirst(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
int main() {
  long long n, d;
  vector<pair<long long, long long> > friends;
  cin >> n >> d;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    friends.push_back(make_pair(a, b));
  }
  sort(friends.begin(), friends.end(), compFirst);
  vector<long long> sums;
  sums.push_back(0);
  for (int i = 0; i < n; ++i) sums.push_back(sums[i] + friends[i].second);
  long long index = 0, max = 0;
  for (int i = 0; i < n; ++i) {
    for (; index == n - 1 || friends[index + 1].first < friends[i].first + d;
         ++index) {
      if (index == n - 1) break;
    }
    if (sums[index + 1] - sums[i] > max) max = sums[index + 1] - sums[i];
  }
  cout << max << endl;
}
