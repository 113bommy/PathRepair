#include <bits/stdc++.h>
using namespace std;
void dbg(char* fmt, ...) {}
const int N = 120000;
int c[N];
long long f[N];
int main() {
  int k[3];
  int t[3];
  for (int i = 0; i < 3; ++i) scanf("%d", &k[i]);
  for (int i = 0; i < 3; ++i) scanf("%d", &t[i]);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
    f[i] = c[i];
  }
  for (int i = 0; i < 3; ++i) {
    k[i] = min(k[i], n);
    vector<long long> q;
    for (int j = 0; j < k[i]; ++j) q.push_back(0);
    int first = 0;
    for (int j = 0; j < n; ++j) {
      if (f[j] < q[first]) f[j] = q[first];
      f[j] += t[i];
      q.push_back(f[j]);
      ++first;
    }
    for (int j = 0; j < n; ++j) {
      dbg("%d ", f[j]);
    }
    dbg("\n");
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) res = max(res, f[i] - c[i]);
  cout << res << endl;
  return 0;
}
