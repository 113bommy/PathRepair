#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
  if (!a) return b;
  return GCD(b % a, a);
}
vector<long long> ans;
map<long long, vector<long long>> divsMap;
vector<long long> getDivs(long long x);
void go(long long x, int k) {
  if (x == 1) {
    ans.push_back(x);
    return;
  }
  if (!k) {
    ans.push_back(x);
    return;
  }
  if (ans.size() >= 100000) return;
  if (divsMap.find(x) == divsMap.end()) {
    divsMap[x] = getDivs(x);
  }
  vector<long long>& div = divsMap[x];
  for (int i = (0); i < (int)(div.size()); i++) {
    go(div[i], k - 1);
  }
}
vector<long long> getDivs(long long x) {
  vector<long long> ret;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      ret.push_back(i);
      if (x / i != i) ret.push_back(x / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
int main() {
  clock_t startTime = clock();
  ios_base::sync_with_stdio(false);
  long long x, k;
  cin >> x >> k;
  if (!k)
    cout << x << "\n";
  else if (x == 1)
    cout << "1\n";
  else {
    if (k >= 100000) {
      for (int i = (0); i < (int)(100000); i++) cout << "1 ";
    } else {
      vector<long long> div = getDivs(x);
      for (int i = (0); i < (int)(div.size()); i++) {
        divsMap[div[i]] = getDivs(div[i]);
        vector<long long> D = getDivs(div[i]);
      }
      go(x, k);
      for (int i = (0); i < (int)(min(100000, (int)ans.size())); i++)
        cout << ans[i] << " ";
    }
  }
  clock_t endTime = clock();
  cerr << "\nTime:" << double(endTime - startTime) / CLOCKS_PER_SEC
       << " seconds\n";
  return 0;
}
