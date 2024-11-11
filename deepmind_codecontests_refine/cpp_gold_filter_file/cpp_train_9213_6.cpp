#include <bits/stdc++.h>
using namespace std;
int n, k;
int cache[1005];
int get_mex(vector<int> mex) {
  sort(mex.begin(), mex.end());
  mex.resize(unique(mex.begin(), mex.end()) - mex.begin());
  for (int i = 0; i < (int)mex.size(); i++) {
    if (mex[i] != i) return i;
  }
  return (int)mex.size();
}
int slow_grundy(int x) {
  if (x == 0) return 0;
  int &res = cache[x];
  if (res != -1) return res;
  vector<int> mex;
  mex.push_back(slow_grundy(x - 1));
  if (x % 2 == 0) {
    if (k % 2 == 0)
      mex.push_back(0);
    else
      mex.push_back(slow_grundy(x / 2));
  }
  return res = get_mex(mex);
}
int fast_grundy(int x) {
  if (x < 5) return slow_grundy(x);
  if (x % 2 == 1) return 0;
  vector<int> mex;
  mex.push_back(0);
  if (k % 2 == 1) mex.push_back(fast_grundy(x / 2));
  return get_mex(mex);
}
void solve() {
  memset(cache, -1, sizeof(cache));
  scanf("%d%d", &n, &k);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sum ^= fast_grundy(x);
  }
  if (sum == 0)
    puts("Nicky");
  else
    puts("Kevin");
}
int main() {
  solve();
  return 0;
}
