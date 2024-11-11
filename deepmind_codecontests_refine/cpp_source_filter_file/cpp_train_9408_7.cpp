#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
map<int, vector<int> > cnt;
map<int, int> mp;
map<int, int> size;
int N;
long long mod;
long long C(long long a, long long b) {
  if (b == 1) return a;
  if (b == 2) return a * (a - 1) / 2LL;
  return 1LL;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a;
    scanf(" %d", &a);
    cnt[a].push_back(i);
    size[a]++;
  }
  for (int i = 1; i <= N; i++) {
    int a;
    scanf(" %d", &a);
    cnt[a].push_back(i);
    size[a]++;
  }
  cin >> mod;
  long long ans = 1LL;
  for (map<int, vector<int> >::iterator it = cnt.begin(); it != cnt.end();
       it++) {
    mp.clear();
    int k = size[it->first];
    for (int j = 0; j < it->second.size(); j++) mp[it->second[j]]++;
    for (map<int, int>::iterator it2 = mp.begin(); it2 != mp.end(); it2++) {
      ans = (ans * C(k, it2->second)) % mod;
      k -= it2->second;
    }
  }
  cout << ans << endl;
  return 0;
}
