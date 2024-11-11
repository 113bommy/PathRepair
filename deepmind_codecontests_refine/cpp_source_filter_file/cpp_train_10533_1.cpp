#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> ar[7005];
vector<int> con[7005];
map<long long, int> cnt;
map<long long, int> vis;
int N;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> ar[i].first;
    cnt[ar[i].first]++;
  }
  for (int i = 0; i < N; i++) cin >> ar[i].second;
  long long sum = 0ll;
  for (int i = 0; i < N; i++) {
    if (vis[ar[i].first] || cnt[ar[i].first] == 1) {
      continue;
    }
    vector<int> vc;
    for (int j = 0; j < N; j++) {
      if (vis[ar[j].first]) {
        continue;
      }
      if ((ar[j].first & ar[i].first) == ar[j].first) {
        sum += ar[j].second;
        vc.push_back(ar[j].first);
      }
    }
    for (int j = 0; j < vc.size(); j++) vis[vc[j]] = true;
    vis[ar[i].first] = true;
  }
  cout << sum << endl;
  return (0);
}
