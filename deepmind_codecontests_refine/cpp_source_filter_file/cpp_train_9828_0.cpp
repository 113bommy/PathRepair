#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
priority_queue<long long, vector<long long>, greater<long long> > heap;
long long g[N];
int i, mj;
void ins(int v, int c) {
  int j1 = min((i - min(c, i)) / 2, mj);
  int m1 = j1 + min(c, i);
  for (int j = mj; j >= j1; --j) {
    g[j] = heap.top();
    heap.pop();
  }
  for (int j = mj + 1; j <= m1 + 1; ++j) g[j] = -1e18;
  int l = j1;
  while (g[l + 1] > v) ++l;
  int j = l;
  long long sum = 0;
  for (int nj = l + 1; nj <= m1; ++nj) {
    while (i - j - nj < 0) {
      assert(j >= j1);
      sum += g[j];
      --j;
    }
    g[nj + 1] += g[nj];
    g[nj] = max(g[nj], (long long)(nj - j) * v - sum);
    g[nj + 1] -= g[nj];
    sum += g[nj];
  }
  for (int j = j1; j <= m1; ++j) heap.push(g[j]);
  i += c;
  mj = m1;
}
int main() {
  int n;
  cin >> n;
  map<int, int> c;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ++c[x];
    sum += x;
  }
  heap.push(g[0] = 1e9 + 5);
  for (auto pr = c.end(); pr != c.begin();) {
    --pr;
    ins(pr->first, pr->second);
  }
  long long ans = 0;
  for (int i = 1; i <= mj; ++i) {
    ans += max(0LL, heap.top());
    heap.pop();
  }
  cout << sum - ans << endl;
}
