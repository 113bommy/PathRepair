#include <bits/stdc++.h>
using namespace std;
int a, b, k, bj[100000], ans;
vector<int> prime;
void dfs(const int v, int s, unsigned int ii, int cc, int tq) {
  if (ii + 1 > prime.size()) {
    if (cc == 0) return;
    ans += v / (tq * s);
    return;
  }
  int p = prime[ii];
  dfs(v, s, ii + 1, cc, tq);
  if (s * p <= v) dfs(v, s * p, ii + 1, cc + 1, tq * -1);
}
int calc(int v) {
  if (k <= v && v / k < k) return 1;
  if (k > v && v / k < k) return 0;
  ans = v / k;
  dfs(v / k, 1, 0, 0, 1);
  return ans;
}
void init() {
  int i, j;
  for (i = 2; i <= k; i++) bj[i] = 1;
  for (i = 2; i <= k - 1; i++)
    if (bj[i]) {
      prime.push_back(i);
      for (j = i * 2; j <= k; j += i) bj[j] = 0;
    }
}
bool work(int v) {
  for (int i = 2; i * i <= v; i++)
    if (v % i == 0) return 0;
  return 1;
}
int main() {
  cin >> a >> b >> k;
  if (!work(k)) {
    cout << 0 << endl;
    return 0;
  }
  if (b / k >= k) init();
  cout << calc(b) - calc(a - 1) << endl;
}
