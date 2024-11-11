#include <bits/stdc++.h>
using namespace std;
int vis[100005], box[100005];
int n;
vector<int> save, prime;
void init() {
  for (int i = 2; i <= 100000; i++)
    if (!vis[i]) {
      prime.push_back(i);
      for (int j = i + i; j <= 100000; j += i) vis[j] = 1;
    }
}
int main() {
  init();
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> box[i];
    if (box[i] == 1) cnt++;
  }
  for (int i = 0; i < prime.size(); i++) {
    if (cnt % prime[i] == 0) {
      save.push_back(prime[i]);
      while (cnt % prime[i] == 0) {
        cnt /= prime[i];
      }
    }
    if (cnt == 1) break;
  }
  long long ans = 999999999999999, now = 0;
  if (save.size() == 0)
    cout << -1;
  else {
    vector<int> v;
    for (int i = 0; i < save.size(); i++) {
      now = 0;
      for (int j = 0; j < n; j++) {
        if (box[j] == 1) v.push_back(j);
        if (v.size() == save[i]) {
          int index = save[i] / 2;
          for (int k = 0; k < save[i]; k++) now += abs(v[k] - v[index]);
          v.clear();
        }
      }
      if (now < ans) ans = now;
    }
    cout << ans;
  }
  return 0;
}
