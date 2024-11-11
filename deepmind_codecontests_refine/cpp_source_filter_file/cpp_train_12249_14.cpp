#include <bits/stdc++.h>
using namespace std;
vector<int> seive(11111111, 1);
vector<int> prr(111111, 0);
set<int> ssf;
int main() {
  std::ios::sync_with_stdio(false);
  for (int i = 2; i < 3163; i++) {
    if (seive[i] == 1) {
      for (int j = i * i; j <= 10000000; j += i) {
        if (seive[j] == 1) seive[j] = i;
      }
    }
  }
  int mxp = 100000;
  for (int i = 2; i < 10000000; i++) {
    if (seive[i] == 1) {
      if (mxp > 0) {
        ssf.insert(i);
        --mxp;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int zz;
  int flag = -1;
  for (int i = 0; i < n; i++) {
    zz = arr[i];
    vector<int> ret;
    while (seive[zz] != 1) {
      ret.push_back(seive[zz]);
      zz /= seive[zz];
    }
    ret.push_back(zz);
    for (__typeof(ret.begin()) it = ret.begin(); it != ret.end(); it++) {
      if (prr[*it] == 1) {
        flag = i;
        break;
      }
    }
    if (flag != -1) break;
    for (__typeof(ret.begin()) it = ret.begin(); it != ret.end(); it++)
      prr[*it] = 1;
  }
  for (int i = 2; i <= 100000; i++)
    if (prr[i] == 1) {
      ssf.erase(ssf.find(i));
    }
  if (flag != -1) {
    int qw = arr[flag];
    while (1) {
      ++qw;
      zz = qw;
      vector<int> ret;
      while (seive[zz] != 1) {
        ret.push_back(seive[zz]);
        zz /= seive[zz];
      }
      ret.push_back(zz);
      int flag = 0;
      for (__typeof(ret.begin()) it = ret.begin(); it != ret.end(); it++)
        if (prr[*it] == 1) flag = 1;
      if (flag == 0) break;
    }
    zz = qw;
    vector<int> ret;
    while (seive[zz] != 1) {
      ret.push_back(seive[zz]);
      zz /= seive[zz];
    }
    ret.push_back(zz);
    for (__typeof(ret.begin()) it = ret.begin(); it != ret.end(); it++) {
      prr[*it] = 1;
      if (ssf.find((*it)) != ssf.end()) ssf.erase(ssf.find((*it)));
    }
    arr[flag] = qw;
    auto it = ssf.begin();
    for (int i = flag + 1; i <= n - 1; i++) {
      arr[i] = *it;
      ++it;
    }
  }
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << '\n';
}
