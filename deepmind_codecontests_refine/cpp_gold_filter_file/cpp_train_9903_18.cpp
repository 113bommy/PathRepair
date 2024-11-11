#include <bits/stdc++.h>
using namespace std;
bool busy[100001];
long long n, k, job[100001], t[100001], sum;
vector<long> vec;
int main() {
  map<long, long> mp, mp2;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> job[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    if (mp.find(job[i]) == mp.end()) {
      mp[job[i]] = t[i];
      mp2[job[i]] = i;
      busy[i] = 1;
    } else {
      if (t[i] > mp[job[i]]) {
        busy[mp2[job[i]]] = 0;
        busy[i] = 1;
        mp[job[i]] = t[i];
        mp2[job[i]] = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (busy[i]) continue;
    vec.push_back(t[i]);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < k - mp.size(); i++) {
    sum += vec[i];
  }
  cout << sum;
}
